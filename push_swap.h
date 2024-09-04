/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:26:53 by nlambert          #+#    #+#             */
/*   Updated: 2024/09/04 15:35:57 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	bas;
	int	haut;
}		t_stack;

typedef struct s_cmd
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	tot;
}		t_cmd;

long	ft_atol(const char *nptr);
int		ft_error(int argc, char **argv);
int		*ft_index(int *tab, int size);
int		verif_tri(t_stack *t);

t_stack	stack_param(int argc, char **argv);
t_stack	initialize_stack(int argc, char **argv);

void	clean(t_stack *t);
void	algo2(t_stack *t);
void	algo3(t_stack *t);
void	algo4_5(t_stack *t);
void	algo5_plus(t_stack *t);
void	end(t_stack *t);
void	insert_b_to_a(t_stack *t);
void	initialisation_cmd(t_cmd *cmd, int c);
void	check_reverse(t_stack *t, t_cmd *cmd);
void	check_rotate(t_stack *t, t_cmd *cmd);
void	rotate_up(int *stack, int size);
void	rotate_down(int *stack, int size);
void	a_to_b(t_stack *t);
void	opti_half(t_stack *t);
void	insert_b_to_a(t_stack *t);
void	ra(t_stack *t);
void	rb(t_stack *t);
void	rr(t_stack *t);
void	rra(t_stack *t);
void	rrb(t_stack *t);
void	rrr(t_stack *t);
void	sa(t_stack *t);
void	sb(t_stack *t);
void	pa(t_stack *t);
void	pb(t_stack *t);
void	ss(t_stack *t);
int		check_b(t_stack *t);

t_cmd	check_best_rot(t_cmd cmd);
t_cmd	check_best_rev(t_cmd cmd);
t_cmd	check_best(t_cmd cmd, t_cmd cmd_best);
t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int b_of_i);
t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int b_of_i);

#endif
