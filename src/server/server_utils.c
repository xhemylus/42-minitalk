/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:18:27 by abollen           #+#    #+#             */
/*   Updated: 2022/01/14 16:13:03 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nbr)
{
	int long	num;

	num = nbr;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	nbr = num % 10 + '0';
	write(1, &nbr, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = -1;
	while (++i < len)
		ptr[i] = c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ministart(void)
{
	write(1, "PID : ", 7);
	ft_putnbr(getpid());
	write(1, "\n", 1);
}
