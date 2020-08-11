/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:52:49 by machoffa          #+#    #+#             */
/*   Updated: 2020/02/03 17:05:40 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_struct
{
	int					numerosalle;
	char				*s;
	int					parcouru;
	int					x;
	int					y;
	int					f;
	int					start;
	int					end;
	int					dist;
	int					nbtu;
	int					moins;
	int					upflow;
	int					*flow;
	struct s_struct		*mom;
	struct s_struct		**tunnel;
	struct s_struct		*next;
}						t_struct;

typedef struct			s_file
{
	struct s_file		*next;
	struct s_struct		*room;
}						t_file;

typedef struct			s_ant
{
	struct s_file		*tmp;
}						t_ant;

typedef struct			s_data
{
	long long			nb;
	int					i;
	int					j;
	int					k;
	int					se;
	int					error;
	int					maxp;
	int					**count1;
	int					*result;
	t_file				***chemin;
	t_file				***cheminstart;
	t_struct			*first;
	t_struct			*start;
	t_struct			*end;
	t_file				*one;
	t_file				*tmp;
}						t_data;

int						error(int i, t_data *x);
int						lemin(t_data *x);
int						ft_strstrn(const char *h, const char *n, t_data *s);
int						nbrlen(char *s);
int						parsroom(char *line, t_data *s);
int						parstunnel(char *line, t_data *s);
int						flowstartend(t_data *x);
int						updateflow(t_data *x);
void					deletedistmom(t_data *x);
void					calcul(t_data *x, int i);
void					finalprint(t_data *x, int j);
int						nbchemin(t_data *x, int i1);
void					bfs(t_data *x);
int						letter_coords(char *line);

#endif
