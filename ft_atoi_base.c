/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:52:06 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/10 13:20:23 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_skip_prefix(char **sv, int base)
{
	if (base == 16)
	{
		if (**sv == '0' && (*(*sv + 1) == 'x' || *(*sv + 1) == 'X'))
			*sv += 2;
	}
	else if (base == 8)
	{
		if (**sv == '0' && ft_isdigit(*(*sv + 1)))
			*sv += 1;
	}
}

int				ft_atoi_base(char *sv, int bs)
{
	int			rs;
	int			n;
	char		f;
	char		p[16];

	rs = 0;
	bs > 1 || bs < 17 ? ft_charstc(p, bs, "0123456789ABCDEF") : NULL;
	f = *sv == '-' && bs == 10 ? 1 : 0;
	ft_skip_prefix(&sv, bs);
	n = ft_strlen(sv);
	while (n)
	{
		if (ft_strchr(p, *sv))
		{
			if (ft_isdigit(*sv))
				rs = (*sv - '0') + (rs * bs);
			else 
				rs = (*sv - '7') + (rs * bs);
		}
		++sv;
		--n;
	}
	return (f == 1 ? -rs: rs);
}
