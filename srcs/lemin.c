/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:57:56 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/08 14:57:32 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void		findthepath(t_data *x)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	while (++i < x->maxp)
	{
		if (i == 0)
		{
			k = x->result[0];
			continue ;
		}
		if (x->result[i] < k)
		{
			j = i;
			k = x->result[i];
		}
	}
	finalprint(x, j);
}

static void		freex(t_data *x)
{
	while (x->start)
	{
		free(x->start->s);
		x->start = x->start->next;
	}
}

int				lemin(t_data *x)
{
	int i;

	i = -1;
	if (flowstartend(x) == -1)
		return (-1);
	while (++i < x->maxp)
	{
		bfs(x);
		if (updateflow(x) == -1)
		{
			x->maxp = i;
			break ;
		}
		deletedistmom(x);
		if (nbchemin(x, i) == -1 && (x->maxp = i))
			break ;
		calcul(x, i);
	}
	if (i == 0 && (error(0, x)))
		return (-1);
	findthepath(x);
	freex(x);
	return (1);
}
