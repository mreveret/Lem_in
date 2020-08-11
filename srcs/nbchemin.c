/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbchemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:44:54 by machoffa          #+#    #+#             */
/*   Updated: 2020/01/23 16:21:38 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void		initnbchemin(t_data *x, int i1, int i)
{
	int			j;
	t_struct	*tmp;

	j = -1;
	tmp = x->start;
	while (++j < i)
	{
		if (!((x->chemin[i1][j] = (t_file *)malloc(sizeof(t_file)))))
			return ;
		x->chemin[i1][j]->room = tmp;
		x->chemin[i1][j]->next = NULL;
		x->cheminstart[i1][j] = x->chemin[i1][j];
	}
}

static int		stockpath(t_data *x, int i1, int i, int j)
{
	int			k;
	t_struct	*tmp;
	t_file		*tmp2;

	while (++j < i && (tmp = x->start))
	{
		while (tmp->end != 1)
		{
			k = tmp->upflow;
			while (k < tmp->nbtu && tmp->flow[k] != 1)
				k++;
			if (k == tmp->nbtu)
				return (-1);
			tmp->upflow = k + 1;
			if (!(tmp2 = (t_file *)malloc(sizeof(t_file))))
				return (-1);
			tmp2->room = tmp->tunnel[k];
			tmp2->next = NULL;
			x->chemin[i1][j]->next = tmp2;
			x->chemin[i1][j] = x->chemin[i1][j]->next;
			tmp = tmp->tunnel[k];
			tmp->upflow = 0;
		}
	}
	return (1);
}

int				nbchemin(t_data *x, int i1)
{
	if (i1 == 0)
	{
		if (!(x->chemin =
			(t_file ***)malloc(sizeof(t_file **) * (x->maxp + 1))))
			return (-1);
		if (!(x->cheminstart =
			(t_file ***)malloc(sizeof(t_file **) * (x->maxp + 1))))
			return (-1);
	}
	if (!(x->chemin[i1] = (t_file **)malloc(sizeof(t_file *) * (i1 + 1))))
		return (-1);
	if (!(x->cheminstart[i1] = (t_file **)malloc(sizeof(t_file *) * (i1 + 1))))
		return (-1);
	initnbchemin(x, i1, i1 + 1);
	if (!(stockpath(x, i1, i1 + 1, -1)))
		return (-1);
	return (1);
}
