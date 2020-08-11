/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:51:58 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/08 14:30:00 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		check1(char *line, t_data *s)
{
	if (line[0] == '#')
	{
		if (line[0] == '#' && (ft_strcmp(line, "##start") == 0) && (s->se = 1))
			return (1);
		if (line[0] == '#' && (ft_strcmp(line, "##end") == 0) && (s->se = 2))
			return (1);
		return (1);
	}
	if ((line[0] == '-' && ft_str_is_numeric(line + 1) == 1)
		|| ft_str_is_numeric(line) == 1)
	{
		if (s->nb != 0)
			return (-3);
		s->nb = ft_atoi(line);
		if (s->nb <= 0 || s->nb > 2147483647)
			return (-3);
		return (1);
	}
	return (0);
}

void	init_t_data(t_data *s)
{
	s->i = 0;
	s->j = -1;
	s->se = 0;
	s->nb = 0;
	s->error = 0;
}

int		error(int i, t_data *x)
{
	if (x->error == 1)
		return (-1);
	ft_putstr("ERROR\n");
	if (i == 0)
		ft_putstr("not a valid line\n");
	if (i == -1)
		ft_putstr("wrong room name\n[ROOM NAME] [X_COORDS] [Y_COORDS]\n");
	if (i == -2)
		ft_putstr("wrong tunnel\n[ROOM1_NAME]-[ROOM2_NAME]\n");
	if (i == -3)
		ft_putstr("ant number is wrong, you can only set-up ant number once\n");
	if (i == -4)
	{
		ft_putstr("There is no #start or #end room\nput #start or #end before");
		ft_putstr(" a room name\n#start\n[ROOM NAME] [X_COORDS] [Y_COORDS]\n");
	}
	x->error = 1;
	return (1);
}

int		main(void)
{
	t_data	*s;
	char	*line;
	int		ret;

	if (!(s = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	init_t_data(s);
	while (get_next_line(0, &line) > 0)
	{
		ret = check1(line, s);
		if (ret == 0)
			ret = parsroom(line, s);
		if (ret == 0)
			ret = parstunnel(line, s);
		(ret < 0) ? free(line) : 12;
		if (ret < 0 && error(ret, s))
			break ;
		ft_putendl(line);
		free(line);
	}
	if ((s->i == 0 || s->nb <= 0) && error(0, s))
		return (-1);
	ft_putchar('\n');
	lemin(s);
	return (0);
}
