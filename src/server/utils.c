/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:10:53 by abollen           #+#    #+#             */
/*   Updated: 2022/01/14 16:15:35 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	convert(char *str, int i)
{
	int	sortie;

	sortie = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		sortie *= 10;
		sortie += str[i] - '0';
		i++;
	}
	return (sortie);
}

int	ft_atoi(char *str)
{
	int	signe;
	int	sortie;
	int	i;

	i = 0;
	signe = 1;
	sortie = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	sortie = convert(str, i);
	return (sortie * signe);
}
