/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:15:54 by abollen           #+#    #+#             */
/*   Updated: 2022/01/14 16:15:19 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

// UTILS
size_t	ft_strlen(const char *str);
void	ft_error(char *str);
int		convert(char *str, int i);
int		ft_atoi(char *str);

// SERVER UTILS
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	*ft_memset(void *b, int c, size_t len);
void	ministart(void);
void	ft_bzero(void *s, size_t n);

// CLIENT UTILS I
int		ft_isnum(char *str);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
void	receipt(int citrus);

#endif