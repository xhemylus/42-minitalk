/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:19:57 by abollen           #+#    #+#             */
/*   Updated: 2022/01/19 21:12:58 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_revstring(char *str, int len)
{
	int		i;
	char	temp;

	i = -1;
	while (++i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return (str);
}

static int	ft_intlen(long int temp)
{
	int	len;

	if (temp == 0)
		return (1);
	len = 0;
	if (temp < 0)
	{
		len++;
		temp *= -1;
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	long int		temp;
	int				len;
	char			*dst;

	i = -1;
	temp = n;
	len = ft_intlen(temp);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (temp < 0)
		temp = temp * -1;
	if (temp == 0)
		dst[++i] = '0';
	while (temp > 0)
	{
		dst[++i] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		dst[++i] = '-';
	dst[++i] = '\0';
	return (ft_revstring(dst, len));
}

void	receipt(int citrus)
{
	if (citrus == SIGUSR1)
	{
		write(1, "Successful Operation\n", 21);
		exit(0);
	}
}
