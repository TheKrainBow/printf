#include "srcs/ft_printf.h"

int main()
{
	ft_printf("%-153.61d%0105.36i%-77.70u%-80p\n", 1957997026, 1534377111, 2603846243u, (void*)17500891794874329626lu);
	printf("%-153.61d%0105.36i%-77.70u%-80p\n", 1957997026, 1534377111, 2603846243u, (void*)17500891794874329626lu);
}