/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 05:32:47 by magostin          #+#    #+#             */
/*   Updated: 2019/11/17 20:33:16 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	ft_pow(int a, int b)
{
	int temp;

	temp = a;
	while (b > 1)
	{
		a *= temp;
		b--;
	}
	if (b == 0)
		return (1);
	return (a);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd2(int i, int n, int neg, int fd)
{
	if (neg == -1)
	{
		write(fd, "-", 1);
		n *= neg;
		i--;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd((n / ft_pow(10, i)) % 10 + '0', fd);
		i--;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		temp;
	int		neg;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == -2147483648)
		return ;
	temp = n;
	i = 0;
	neg = 1;
	if (temp < 0)
	{
		i++;
		temp *= -1;
		neg = -1;
	}
	while (temp >= 10)
	{
		i++;
		temp /= 10;
	}
	i++;
	ft_putnbr_fd2(i, n, neg, fd);
}
