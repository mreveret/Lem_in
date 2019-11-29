/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:52:49 by machoffa          #+#    #+#             */
/*   Updated: 2019/11/27 15:54:07 by machoffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_struct
{
		int				numerosalle;
		char			*s;
		int				x;
		int				y;
		int				f;
		int				start;
		int				end;
		struct s_list	*next;
		struct s_list	*prev;
}						t_struct;

int		main(int ac, char **av);
int		lemin(void);

#endif
