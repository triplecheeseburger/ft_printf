#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("ft return: %d\n", ft_printf("%X\n", 10));
	printf("pf return: %d\n", printf("%X\n", 10));
}
