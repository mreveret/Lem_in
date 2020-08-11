/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:44:40 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/03 16:02:27 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		bfs_mom_dist(t_file *bfs, t_file *bfs2, int i, int j)
{
	bfs2->room = bfs->room->tunnel[i];
	if (bfs->room->tunnel[i]->parcouru == 1 && bfs->room->flow[i] == 0)
		bfs2->room->moins = 1;
	if (bfs->room->flow[i] == -1)
		if ((bfs2->room->dist == 0 && bfs2->room->start != 1)
				|| bfs2->room->dist > bfs->room->dist - 1)
		{
			bfs2->room->mom = bfs->room;
			bfs2->room->dist = bfs->room->dist - 1;
			j = 1;
		}
	if (bfs->room->flow[i] != -1)
		if (bfs2->room->dist == 0 || bfs2->room->dist > bfs->room->dist + 1)
		{
			bfs2->room->mom = bfs->room;
			bfs2->room->dist = bfs->room->dist + 1;
			j = 1;
		}
	return (j);
}

static void		bfs1(t_data *x, t_file *bfs, int i)
{
	t_file		*bfs2;
	int			j;

	j = 0;
	if (bfs->room->end != 1 && bfs->room->tunnel[i] != bfs->room->mom &&
			((bfs->room->moins == 1 && bfs->room->flow[i] == -1)
			|| (bfs->room->moins == 0 && bfs->room->flow[i] != 1)))
	{
		if (!(bfs2 = (t_file *)malloc(sizeof(t_file))))
			return ;
		j = bfs_mom_dist(bfs, bfs2, i, j);
		if (j != 1)
			free(bfs2);
		if (j == 1)
		{
			bfs2->next = NULL;
			x->tmp = bfs;
			while (bfs->next)
				bfs = bfs->next;
			bfs->next = bfs2;
			bfs = x->tmp;
		}
		j = 0;
	}
}

static void		initbfs(t_data *x, t_file *bfs)
{
	t_struct	*tmp;

	tmp = x->start;
	bfs->room = tmp;
	bfs->next = NULL;
	x->one = bfs;
}

void			bfs(t_data *x)
{
	t_file		*bfs;
	t_file		*bfs3;
	int			i;

	if (!(bfs = (t_file *)malloc(sizeof(t_file))))
		return ;
	initbfs(x, bfs);
	while (bfs != NULL)
	{
		i = -1;
		while (++i < bfs->room->nbtu)
			bfs1(x, bfs, i);
		bfs->room->moins = 0;
		bfs = bfs->next;
	}
	bfs = x->one;
	while (bfs)
	{
		bfs3 = bfs;
		bfs = bfs->next;
		free(bfs3);
	}
	free(bfs);
	bfs = NULL;
}
