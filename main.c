#include "srcs/ft_printf.h"

int main()
{
	ft_printf("|%-30.22lld|\n", LLONG_MIN);
	printf("|%-30.22lld|\n", LLONG_MIN);
}