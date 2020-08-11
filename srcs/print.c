/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:15:01 by machoffa          #+#    #+#             */
/*   Updated: 2020/01/23 16:07:25 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void	finalfinal(t_data *x, int *i, t_ant **nbant, int ant)
{
	x->chemin[i[1]][i[0]] = x->cheminstart[i[1]][i[0]];
	x->chemin[i[1]][i[0]] = x->chemin[i[1]][i[0]]->next;
	if (!(nbant[ant] = (t_ant *)malloc(sizeof(t_ant))))
		return ;
	nbant[ant]->tmp = x->chemin[i[1]][i[0]];
}

static void	final(t_ant **nbant, int ant)
{
	int		k;

	k = -1;
	while (++k < ant)
	{
		if (nbant[k]->tmp != NULL)
		{
			ft_putstr("L");
			ft_putnbr(k);
			ft_putchar('-');
			ft_putstr(nbant[k]->tmp->room->s);
			nbant[k]->tmp = nbant[k]->tmp->next;
			ft_putchar(' ');
		}
	}
}

static void	antrepartition(t_data *x, int j, int *k, t_ant **nbant)
{
	int		ant;
	int		i[2];

	ant = 0;
	i[1] = j;
	while (ant < x->nb)
	{
		i[0] = -1;
		while (++i[0] <= j)
			if (ant < x->nb && k[i[0]] > 0)
			{
				finalfinal(x, i, nbant, ant);
				k[i[0]]--;
				ant++;
			}
		final(nbant, ant);
		ft_putchar('\n');
	}
	i[0] = -1;
	while (++i[0] < x->nb)
		while (nbant[i[0]]->tmp != NULL)
		{
			final(nbant, ant);
			ft_putchar('\n');
		}
}

void		finalprint(t_data *x, int j)
{
	int		i;
	int		*k;
	t_ant	**nbant;

	if (!(nbant = (t_ant **)malloc(sizeof(t_ant *) * (x->nb + 1))))
		return ;
	if (!(k = (int *)malloc(sizeof(int) * (j + 1))))
		return ;
	i = -1;
	while (++i <= j)
		k[i] = x->result[j] - x->count1[j][i] + 1;
	antrepartition(x, j, k, nbant);
	i = -1;
	while (++i < x->nb)
		free(nbant[i]);
	free(nbant);
	free(k);
}
