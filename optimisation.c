/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:46:42 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:51:20 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	check_best_rot(t_cmd cmd)
{
	while (cmd.ra && cmd.rb)
	{
		cmd.ra--;
		cmd.rb--;
		cmd.tot ++;
	}
	while (cmd.ra)
	{
		cmd.ra--;
		cmd.tot ++;
	}
	while (cmd.rb)
	{
		cmd.rb--;
		cmd.tot++;
	}
	return (cmd);
}

t_cmd	check_best_rev(t_cmd cmd)
{
	while (cmd.rra && cmd.rrb)
	{
		cmd.rra--;
		cmd.rrb--;
		cmd.tot++;
	}
	while (cmd.rra)
	{
		cmd.rra--;
		cmd.tot ++;
	}
	while (cmd.rrb)
	{
		cmd.rrb--;
		cmd.tot ++;
	}
	return (cmd);
}

t_cmd	check_best(t_cmd cmd, t_cmd cmd_best)
{
	t_cmd	clone;

	clone = cmd;
	cmd = check_best_rot(cmd);
	cmd = check_best_rev(cmd);
	clone.tot = cmd.tot;
	if (cmd_best.tot > cmd.tot)
		cmd_best = clone;
	return (cmd_best);
}

void	insert_b_to_a(t_stack *t)
{
	t_cmd	cmd_best;
	t_cmd	cmd;
	int		i;

	initialisation_cmd(&cmd, 0);
	while (t->size_b)
	{
		initialisation_cmd(&cmd_best, 100000);
		i = 0;
		while (i < t->size_b)
		{
			cmd = edit_command_a(t, cmd, t->b[i]);
			cmd = edit_command_b(t, cmd, t->b[i]);
			cmd_best = check_best(cmd, cmd_best);
			i ++;
			initialisation_cmd(&cmd, 0);
		}
		check_rotate(t, &cmd_best);
		check_reverse(t, &cmd_best);
		pa(t);
		if (t->a[0] < t->bas)
			t->bas = t->a[0];
	}
}

void	end(t_stack *t)
{
	if (t->a[0] <= t->size_a / 2 + 1)
		while (t->a[0] != 1)
			rra(t);
	else
		while (t->a[0] != 1)
			ra(t);
}
