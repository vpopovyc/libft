/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:33:00 by vpopovyc          #+#    #+#             */
/*   Updated: 2016/12/17 17:44:39 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*beer;
	size_t	i;

	i = -1;
	beer = NULL;
	if (s && f)
	{
		if (!(beer = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[++i])
			beer[i] = f(i, s[i]);
	}
	return (beer);
}
