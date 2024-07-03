/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:46:24 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:48:54 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialisation_cmd(t_cmd *cmd, int c)
{
	cmd->ra = c;
	cmd->rb = c;
	cmd->rra = c;
	cmd->rrb = c;
	cmd->tot = c * 2;
}

void	check_reverse(t_stack *t, t_cmd *cmd)
{
	while (cmd->rra && cmd ->rrb)
	{
		rrr(t);
		cmd->rra--;
		cmd->rrb--;
	}
	while (cmd->rra)
	{
		rra(t);
		cmd->rra--;
	}
	while (cmd->rrb)
	{
		rrb(t);
		cmd->rrb--;
	}
}

void	check_rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->ra && cmd->rb)
	{
		rr(t);
		cmd->ra--;
		cmd->rb--;
	}
	while (cmd->ra)
	{
		ra(t);
		cmd->ra--;
	}
	while (cmd->rb)
	{
		rb(t);
		cmd->rb--;
	}
}

/*Détermine la position optimale pour insérer un élément dans la pile A*/
t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int b_of_i)
{
	int	i;
	int	total_shift_a;

	total_shift_a = -1;
	i = 0;
	if (b_of_i < t->a[0] && b_of_i > t->a [t->size_a - 1])
		total_shift_a = 0;
	while (i < t->size_a && total_shift_a != 0)
	{
		if (b_of_i < t->bas && t->a[i] == t->bas)
			total_shift_a = i;
		else if (b_of_i > t->a[i] && b_of_i < t->a[i + 1] && i < t->size_a - 1)
			total_shift_a = i + 1;
		i ++;
	}
	if (total_shift_a > t->size_a / 2)
		cmd.rra = t->size_a - total_shift_a;
	else
		cmd.ra = total_shift_a;
	return (cmd);
}

t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int b_of_i)
{
	int	total_shift_b;

	total_shift_b = 0;
	while (t->b[total_shift_b] != b_of_i)
		total_shift_b ++;
	if (total_shift_b > t->size_b / 2)
		cmd.rrb = t->size_b - total_shift_b;
	else
		cmd.rb = total_shift_b;
	return (cmd);
}
