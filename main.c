/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:10:24 by nlambert          #+#    #+#             */
/*   Updated: 2024/06/20 16:59:03 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Cette fonction libère la mémoire allouée pour les piles A et B dans la structure t_stack.*/
void	clean(t_stack *t)
{
    free(t->a);
    free(t->b);
}
/*
Verifie mes arguments
Si +/= deux arguments initalise pile A et B avec
Verif si les piles sont triees, si vide nettoie la memoire et termine
En fonction du nombre d'elements appel un algo different
Pour finir clean la memoire puis termine le programme*/
int main(int argc, char **argv)
{
	t_stack t;
	if (ft_error(argc, argv))
		return (0);
	if (argc > 2)
	{
		t = stack_param(argc, argv);
		if (verif_tri(&t) || !t.a || !t.b)
		{
			clean(&t);
			return (0);
		}
        if (argc == 3)
            algo2(&t);
        if (argc == 4)
            algo3(&t);
        if (argc > 4 && argc < 7)
            algo4_5(&t);
        if (argc > 6)
            algo5_plus(&t);
        clean(&t);
    }
    return (0);
}
