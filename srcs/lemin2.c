/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:10:00 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/03 17:11:16 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			flowstartend(t_data *x)
{
	t_struct	*tmp;
	int			j[3];

	tmp = x->first;
	j[1] = 0;
	j[2] = 0;
	while (tmp && (j[0] = -1))
	{
		if (tmp->start == 1 && (x->start = tmp))
			j[1]++;
		if (tmp->end == 1 && (x->end = tmp))
			j[2]++;
		if (!(tmp->flow = (int *)malloc(sizeof(int) * (tmp->nbtu + 1))))
			return (-1);
		while (++j[0] < tmp->nbtu)
			tmp->flow[j[0]] = 0;
		tmp = tmp->next;
	}
	if ((j[1] != 1 || j[2] != 1) && error(-4, x))
		return (-1);
	tmp = x->end;
	x->maxp = tmp->nbtu;
	tmp = x->start;
	x->maxp = (tmp->nbtu < x->maxp) ? tmp->nbtu : x->maxp;
	return (1);
}

int			updateflow(t_data *x)
{
	t_struct	*tmp;
	int			i;

	tmp = x->end;
	if (tmp->mom == NULL)
		return (-1);
	while (tmp->start != 1)
	{
		i = 0;
		while (tmp->tunnel[i] != tmp->mom)
			i++;
		tmp->flow[i] = (tmp->flow[i] == 0) ? -1 : 0;
		i = 0;
		while (tmp->mom->tunnel[i] != tmp)
			i++;
		tmp->mom->flow[i] = (tmp->mom->flow[i] == 0) ? 1 : 0;
		if (tmp->start != 1 && tmp->end != 1)
			tmp->parcouru = 1;
		tmp = tmp->mom;
	}
	return (1);
}

void		deletedistmom(t_data *x)
{
	t_struct *tmp;

	tmp = x->first;
	while (tmp)
	{
		tmp->upflow = 0;
		tmp->dist = 0;
		tmp->mom = NULL;
		tmp = tmp->next;
	}
}

void		calcul(t_data *x, int i)
{
	int		count[2];

	if (i == 0)
		if (!(x->count1 = (int **)malloc(sizeof(int *) * (x->maxp + 1))))
			return ;
	if (i == 0)
		if (!(x->result = (int *)malloc(sizeof(int) * (x->maxp + 1))))
			return ;
	count[0] = -1;
	if (!(x->count1[i] = (int *)malloc(sizeof(int) * (i + 1))))
		return ;
	while (++count[0] < i + 1)
	{
		count[1] = 0;
		x->chemin[i][count[0]] = x->cheminstart[i][count[0]];
		while (x->chemin[i][count[0]]->next && (count[1] = count[1] + 1))
			x->chemin[i][count[0]] = x->chemin[i][count[0]]->next;
		x->count1[i][count[0]] = count[1];
	}
	count[1] = 0;
	count[0] = -1;
	while (++count[0] < i + 1)
		count[1] += x->count1[i][count[0]];
	count[0] = (x->nb + count[1]) % (i + 1);
	x->result[i] = (x->nb + count[1]) / (i + 1) - 1 + count[0];
}
