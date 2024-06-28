/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:19:16 by nlambert          #+#    #+#             */
/*   Updated: 2024/06/18 16:11:38 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Cette fonction vérifie si les arguments sont bien des chiffres.*/
int ft_error(int argc, char **argv)
{
    int			i;
    int			j;
    int			count_digits;
    long int	nb;

    i = 1;
    while (i <= argc - 1)
    {
        j = 0;
        count_digits = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (write(2, "Error\n", 6));
            count_digits += argv[i][j] != '0';
            j++;
        }
        nb = ft_atol(argv[i]);
        if (count_digits > 10 || nb > INT_MAX || nb < INT_MIN)
            return (write(2, "Error\n", 6));
        i++;
    }
    return (0);
}
/* Cette fonction convertit une chaîne de caractères en un long int.
Elle gère les cas où la chaîne représente un nombre plus grand que INT_MAX. */
long	ft_atol(const char *nptr)
{
    int			i;
    int			sign;
    long int	nb;

    i = 0;
    sign = 1;
    nb = 0;
    while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if (nptr[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (nptr[i] == '+')
        i++;
    while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
    {
        nb = nb * 10 + (nptr[i] - '0');
        i++;
    }
    return (nb * sign);
}
/*Cette fonction initialise les piles A et B et leur alloue la mémoire pour stocker argc - 1 éléments.
Elle donne également à 'top' la valeur de size_a / 2 et écrase les anciennes valeurs des piles pour
avoir celles de l'index.*/
t_stack	stack_param(int argc, char **argv)
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
/*Cette fonction vérifie si le tableau est déjà trié.
Elle renvoie 1 si c'est le cas, 0 sinon, et envoie
une erreur si elle rencontre deux chiffres identiques.*/
int	verif_tri(t_stack *t)
{
    int	i;
    int	j;

    i = 0;
    while (i < t->size_a - 1)
    {
        j = i + 1;
        while (j < t->size_a)
        {
            if (t->a[i] == t->a[j])
                return (write(2, "Error\n", 6));
            j++;
        }
        i++;
    }
    i = 0;
    while (i < t->size_a - 1)
    {
        if (t->a[i] > t->a[i + 1])
            return (0);
        i++;
    }
    return (1);
}
