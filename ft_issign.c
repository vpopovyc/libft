#include "includes/libft.h"

int	ft_issign(int c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (2);
	return (0);
}
