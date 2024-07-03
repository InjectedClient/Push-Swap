/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:58:55 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:36:30 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo2(t_stack *t)
{
	if (t->a[0] > t->a[1])
		sa(t);
}

void	algo3(t_stack *t)
{
	if (t->a[0] > t->a[1] && t->a[1] < t->a[t->size_a - 1])
	{
		if (t->a[0] < t->a[t->size_a - 1])
			sa(t);
		else if (t->a[1] < t->a[t->size_a - 1])
			ra(t);
	}
	else if (t->a[0] > t->a[1] && t->a[1] > t->a[t->size_a - 1])
	{
		sa(t);
		rra(t);
	}
	else if (t->a[0] < t->a[1])
	{
		if (t->a[0] < t->a[t->size_a - 1] && t->a[1] > t->a[t->size_a - 1])
		{
			sa(t);
			ra(t);
		}
		else if (t->a[0] > t->a[t->size_a - 1])
			rra(t);
	}
}

void	algo4_5(t_stack *t)
{
	if (t->size_a == 5)
	{
		while (t->size_a != 3)
		{
			while (t->a[0] != 1 && t->a[0] != 2)
				ra(t);
			pb(t);
		}
		if (t->b[0] < t->b[1])
			sb(t);
	}
	if (t->size_a == 4)
	{
		while (t->a[0] != 1)
			ra(t);
		pb(t);
	}
	algo3(t);
	while (t->size_b)
		pa(t);
}

void	algo5_plus(t_stack *t)
{
	half_to_b(t);
	algo3(t);
	pa(t);
	t->bas = t->a[0];
	insert_b_to_a(t);
	end(t);
}
