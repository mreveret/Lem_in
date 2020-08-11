/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtunnel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:39:33 by machoffa          #+#    #+#             */
/*   Updated: 2020/01/31 16:42:27 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void		*ft_rea(void *ptr, size_t len)
{
	void	*dup;

	dup = (void*)malloc(len);
	if (ptr)
	{
		if (dup)
			ft_memcpy(dup, ptr, len);
		ft_memdel(&ptr);
	}
	return (dup);
}

static void		stocktunnel(t_struct *tmp, t_struct *tmp2)
{
	t_struct **test;

	if (tmp->nbtu == 0)
	{
		if (!(tmp->tunnel = (t_struct **)malloc(sizeof(t_struct *))))
			return ;
		tmp->tunnel[tmp->nbtu] = tmp2;
	}
	if (tmp->nbtu != 0)
	{
		if (!(test = (t_struct **)
			ft_rea(tmp->tunnel, sizeof(t_struct *) * (tmp->nbtu + 2))))
			return ;
		test[tmp->nbtu] = tmp2;
		tmp->tunnel = test;
	}
	tmp->nbtu++;
}

static int		parstunnel2(char *line, t_data *s, t_struct *tmp, int i)
{
	t_struct *tmp2;

	tmp2 = s->first;
	while (tmp2)
	{
		if (s->k == 3 && !ft_strcmp(tmp2->s, line + i + 1))
			stocktunnel(tmp, tmp2);
		if (s->k == 2 && ft_strncmp(line, tmp2->s, i) == 0)
			stocktunnel(tmp, tmp2);
		tmp2 = tmp2->next;
	}
	if (tmp2 == NULL)
	{
		free(tmp2);
		return (-2);
	}
	free(tmp2);
	return (1);
}

static int		parstunnel1(char *line, t_data *s, t_struct *tmp, int i)
{
	int k;

	k = 0;
	while (tmp)
	{
		if (ft_strstrn(line, tmp->s, s))
		{
			i = 0;
			while (line[i] && line[i] != '-')
				i++;
			if (!(parstunnel2(line, s, tmp, i)))
				return (-2);
			if (k == 1)
				break ;
			k = 1;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (-1);
	return (0);
}

int				parstunnel(char *line, t_data *s)
{
	t_struct	*tmp;
	int			i;
	int			j;

	tmp = s->first;
	i = -1;
	j = 0;
	while (line[++i])
		if (line[i] == '-')
			j = 1;
	if (j == 0)
		return (-2);
	if (parstunnel1(line, s, tmp, i) == -1)
		return (-2);
	return (1);
}
