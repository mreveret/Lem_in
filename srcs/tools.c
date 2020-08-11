/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:21:23 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/03 16:46:26 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		ft_strstrn(const char *h, const char *n, t_data *s)
{
	int i;
	int j;

	i = 0;
	s->k = 0;
	while (h[i] && n[i] && h[i] == n[i])
		i++;
	if (h[i] == '-' && n[i] == '\0' && (s->k = 3))
		return (1);
	while (h[i] != '-')
		i++;
	i++;
	j = 0;
	while (h[i] && n[j] && h[i] == n[j])
	{
		i++;
		j++;
	}
	if (h[i] == '\0' && n[j] == '\0' && (s->k = 2))
		return (1);
	return (0);
}

int		nbrlen(char *s)
{
	int i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) == 1 || s[i] == '-' || s[i] == '+'))
		i++;
	return (i);
}

int		letter_coords(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
		if (!((line[i] >= '0' && line[i] <= '9') || line[i] == ' '))
			return (-1);
	return (1);
}
