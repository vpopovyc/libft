/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:02:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/19 17:02:29 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fdf.h"

char    ft_check_end(char *line)
{
    if (ft_strstr(line, "end of game"))
        return (1);
    return (0);
}

static void     ft_rec_free(t_root *root, t_fdf *head, t_fdf *draw)
{
    if (draw->right == NULL && draw->down == NULL && draw->diag == NULL)
        return (free(draw));
    if (draw->right != NULL)
        ft_rec_free(root, head, draw->right);
    else if (draw->right == NULL && draw->down != NULL)
        ft_rec_free(root, head->down, head->down);
    free(draw);
}

static char    ft_music(t_root *root)
{
    if (root->head == NULL)
    {
        --root->name;
        root->status = 0;
        return (0);
    }
    return (root->status = 1);
}

void    ft_redraw(int kc, t_root *root)
{
    char    *tmp;
    char    *name;

    kc == 18 ? --root->name : 0;
    kc == 19 ? ++root->name : 0;
    root->name < 0 ? root->name = 0 : 0;
    tmp = ft_sstoab(root->name, 10); 
    name = ft_strjoin("logs/", tmp);
    root->status ? ft_rec_free(root, root->head, root->head) : 0;
    ft_parse(open(name, O_RDONLY), root);
    free(tmp);
    free(name);
    if (ft_music(root))
    {
        mlx_destroy_image(root->init, root->img);
        ft_image(root);
        mlx_clear_window(root->init, root->win);
        mlx_put_image_to_window(root->init, root->win, root->img, -1, 0);
    }
}
