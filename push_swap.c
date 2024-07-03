/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:16:58 by nlambert          #+#    #+#             */
/*   Updated: 2024/07/03 16:52:34 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *t)
{
	int	tmp;

	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *t)
{
	int	i;
	int	tmp_a;

	i = 0;
	tmp_a = t->size_a;
	while (tmp_a > 0)
	{
		t->a[tmp_a] = t->a[tmp_a - 1];
		tmp_a --;
	}
	t->a[0] = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i ++;
	}
	t->size_a += 1;
	t->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *t)
{
	int	i;
	int	tmp_b;

	i = 0;
	tmp_b = t->size_b;
	while (tmp_b > 0)
	{
		t->b[tmp_b] = t->b[tmp_b - 1];
		tmp_b --;
	}
	t->b[0] = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i ++;
	}
	t->size_a -= 1;
	t->size_b += 1;
	write(1, "pb\n", 3);
}
