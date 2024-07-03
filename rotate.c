/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:30:52 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:56:36 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(int *stack, int size)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i ++;
	}
	stack[size - 1] = tmp;
}

void	ra(t_stack *t)
{
	rotate_up(t->a, t->size_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *t)
{
	rotate_up(t->b, t->size_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *t)
{
	rotate_up(t->a, t->size_a);
	rotate_up(t->b, t->size_b);
	write(1, "rr\n", 3);
}
