/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/09 17:08:50 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fdf.h"

void		ft_diagonal(t_root *root)
{
	t_fdf	*first;
	t_fdf	*second;
	t_fdf	*tmp_f;
	t_fdf	*tmp_s;

	first = root->head->right;
	second = root->head->down;
	while (second)
	{
		tmp_f = first;
		tmp_s = second;
		while (first)
		{
			first->diag = second;
			first = first->right;
			second = second->right;
		}
		first = tmp_f;
		first = first->down;
		second = tmp_s;
		second = second->down;
	}
}

void		ft_spc(int *x, t_fdf **head, t_fdf **node)
{
	static	t_fdf	*tmp;

	if (*x == 0)
	{
		tmp = *node;
		*head = *node;
		*node = NULL;
		++*x;
		return ;
	}
	tmp->right = *node;
	tmp = *node;
	*node = NULL;
	++*x;
}


t_fdf		*ft_loop(char *line, int n, t_root *root)
{
	t_fdf	*node;
	t_fdf	*head;
	int		x;

	x = 0;
	node = NULL;
	head = NULL;
    if (ft_check_end(line))
        return (NULL);
	while (*line != '\0' && (n == 0 || (n > 0 && x < root->x_max)))
	{
		if (*line == '.')
			node = ft_new_node(n, (int)x, 0, 0x303030);
        else if (ft_toupper(*line) == 'X')
            node = ft_new_node(n, (int)x, 1, 0x909090);
        else if (ft_toupper(*line) == 'O')
            node = ft_new_node(n, (int)x, 1, 0x820202);
        ft_spc(&x, &head, &node);
		++line;
	}
	n > 0 && x < root->x_max ? root->status |= 0x40 : 0;
	n == 0 ? root->x_max = x : 0;
	return (head);
}

int			ft_parse(int fd, t_root *root)
{
	char	*line;
	int		n;
	t_fdf	*up;
	t_fdf	*down;

	n = -1;
	line = NULL;
	if (get_next_line(fd, &line) <= 0)
		return (root->status |= 0x80);
	root->head = ft_loop(line, ++n, root);
    up = root->head;
	while (get_next_line(fd, &line) > 0)
	{
		down = ft_loop(line, ++n, root);
		if (root->status & 0x40)
			exit(ft_printf("Invalid matrix\n"));
		ft_merge(&up, &down);
		up = down;
		free(line);
	}
	root->y_max = n;
    close (fd);
	return (1);
}
