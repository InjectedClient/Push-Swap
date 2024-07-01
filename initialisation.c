/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:48:13 by nlambert          #+#    #+#             */
/*   Updated: 2024/06/20 16:43:53 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Creer un tableau et attribue un index à chaque elément de la pile en fonction
de leur ordre de tri*/
int	*ft_index(int *tab, int size)
{
    int	index;
    int	i;
    int	j;
    int	*tmp;

    tmp = malloc(sizeof(int) * size);
    if (!tmp)
        return (NULL);
    i = 0;
    while (i <= size - 1)
    {
        j = 0;
        index = 0;
        while (j <= size - 1)
        {
            if (tab[i] > tab[j])
                index++;
            j++;
        }
        tmp[i] = index + 1;
        i++;
    }
    free(tab);
    return (tmp);
}
/*Cette fonction initialise les piles A et B et leur alloue la mémoire pour
stocker argc - 1 éléments. Elle donne également à 'haut' la valeur de size_a / 2
et écrase les anciennes valeurs des piles pour avoir celles de l'index.*/
t_stack	initialize_stack(int argc, char **argv)
{
    t_stack	t;

    t.size_a = 0;
    t.size_b = 0;
    t.a = malloc(sizeof(int) * (argc - 1));
    t.b = malloc(sizeof(int) * (argc - 1));
    if (!t.a || !t.b)
        return (t);
    while (t.size_a < argc - 1)
    {
        t.a[t.size_a] = ft_atol(argv[t.size_a + 1]);
        t.size_a++;
    }
    t.bas = 0;
    t.haut = t.size_a / 2;
    t.a = ft_index(t.a, t.size_a);
    return (t);
}
