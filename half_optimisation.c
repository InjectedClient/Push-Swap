/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_optimisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:45:39 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:45:54 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_b(t_stack *t)
{
	return ((t->b[0] >= t->bas)
		&& (t->b[0] <= (t->haut + t->bas) / 2 && t->size_b > 1));
}

void	opti_half(t_stack *t)
{
	int	i;

	i = 0;
	while (!(t->a[i] >= t->bas && t->a[i] <= t->haut) && i < t->size_a)
		i ++;
	if (i > 0 && check_b(t))
		rr(t);
	if (check_b(t))
		rb(t);
}

void	half_to_b(t_stack *t)
{
	int	tmp;

	tmp = t->size_a;
	while (t->size_a >= 3)
	{
		if (t->size_a >= 3)
		{
			if (t->size_b == tmp / 2)
			{
				t->bas = t->haut;
				t->haut = tmp - 3;
			}
			while (!(t->a[0] >= t->bas && t->a[0] <= t->haut))
				ra(t);
			pb(t);
			if (t->size_a == 3)
				break ;
			opti_half(t);
		}
	}
}
