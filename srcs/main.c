/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:51:58 by machoffa          #+#    #+#             */
/*   Updated: 2019/11/27 15:53:22 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		i;
	int		se;
	int		nb;
	t_struct *d;
	char *line;

	i = -1;
	se = 0;
	nb = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] != '#')
			continue ;
		if (line[0] == '#' && line[1] == '#' && ft_strstr(line, "start"))
		{
			i = 1;
			continue ;
		}
		if (line[0] == '#' && line[1] == '#' && ft_strstr(line, "end"))
		{
			i = 2;
			continue ;
		}
		if (ft_str_is_numeric(line) == 1)
		{
			nb = atoi(line);
			continue ;
		}
		while(line[++i])
			if (ft_isspace(line[i]) == 1)
				recuperer coords salles + nom salle
		si je suis au bout de line, tunnel entre 2 salles a mettre dans le char **tab
	}
	printf("hello\n");
	return (0);
}
