/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingroom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:13:51 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/08 14:28:43 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		testname(t_struct *d, t_data *s)
{
	t_struct *tmp;

	tmp = s->first;
	while (s->j > 0 && tmp)
	{
		if (ft_strcmp(d->s, tmp->s) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void		initroom(t_struct *d, t_data *s)
{
	d->parcouru = 0;
	d->mom = NULL;
	d->dist = 0;
	d->moins = 0;
	d->nbtu = 0;
	d->upflow = 0;
	if (s->se == 0 && (d->start = 0))
		d->end = 0;
	if (s->se == 1 && (d->start = 1))
		d->end = 0;
	if (s->se == 2)
	{
		d->start = 0;
		d->end = 1;
	}
	s->se = 0;
}

static void		parsroom1(t_struct *d, t_data *s)
{
	t_struct	*tmp;

	if (s->j == 1)
	{
		tmp = s->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = d;
		d->next = NULL;
		s->i++;
	}
}

static int		parsroom2(t_struct *d, char *line, t_data *s, int i)
{
	if (i > 0 && line[0] == 'L')
		return (-1);
	if (!(d->s = (char *)malloc(sizeof(char) * i + 1)))
		return (-1);
	ft_strncpy(d->s, line, i);
	initroom(d, s);
	if (testname(d, s) == 0)
		return (-1);
	if (letter_coords(line + i + 1) == -1)
		return (-1);
	if ((d->x = ft_atoi(line + i + 1)) < 0)
		return (-1);
	i = i + nbrlen(line + i + 1);
	if ((d->y = ft_atoi(line + i)) < 0)
		return (-1);
	if (s->j == -1)
	{
		s->j = 1;
		s->first = d;
		s->first->next = NULL;
	}
	parsroom1(d, s);
	return (1);
}

int				parsroom(char *line, t_data *s)
{
	int			j[3];
	t_struct	*d;

	j[2] = -1;
	if (!(d = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	while (line[++j[2]] && (j[0] = -1))
		if (ft_isspace(line[j[2]]) == 1)
		{
			if (parsroom2(d, line, s, j[2]) == -1)
			{
				free(d->s);
				free(d);
				return (-1);
			}
			j[1] = 0;
			while (line[++j[0]])
				if (ft_isspace(line[j[0]]) == 1)
					j[1]++;
			if (j[1] > 2)
				return (-1);
			return (1);
		}
	free(d);
	return (0);
}
