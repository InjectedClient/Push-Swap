/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:30:46 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:54:11 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(int *stack, int size)
{
	int	tmp;

	tmp = stack[size - 1];
	while (size > 1)
	{
		stack[size - 1] = stack[size - 2];
		size --;
	}
	stack[0] = tmp;
}

void	rra(t_stack *t)
{
	rotate_down(t->a, t->size_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *t)
{
	rotate_down(t->b, t->size_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *t)
{
	rotate_down(t->a, t->size_a);
	rotate_down(t->b, t->size_b);
	write(1, "rrr\n", 4);
}
