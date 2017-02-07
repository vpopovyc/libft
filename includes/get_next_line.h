/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:03:34 by vpopovyc          #+#    #+#             */
/*   Updated: 2016/12/30 17:02:53 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"

typedef struct		s_gnl
{
	char			*brb;
	char			*pimp;
	char			*adr;
	int				fd;
	long			nbytes;
	struct s_gnl	*next;
}					t_gnl;
int					get_next_line(const int fd, char **line);
#endif
