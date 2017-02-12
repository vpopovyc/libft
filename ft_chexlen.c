#include "includes/libft.h"

size_t	ft_chexlen(char *sv)
{
	size_t len;

	len = 0;
	while (ft_ishex(*sv++))
		++len;
	return (len);
}
