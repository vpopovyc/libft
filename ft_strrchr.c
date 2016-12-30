/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:53:25 by vpopovyc          #+#    #+#             */
/*   Updated: 2016/12/02 14:57:11 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*beer;
	int		beer2;
	int		i;

	i = 0;
	beer2 = ft_strlen(s);
	while (beer2-- >= 0)
	{
		if (*s == c)
		{
			beer = (char*)s;
			i = 1;
		}
		s++;
	}
	if (i)
		return (beer);
	else
		return (NULL);
}
