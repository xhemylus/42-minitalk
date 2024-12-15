/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:20:43 by abollen           #+#    #+#             */
/*   Updated: 2022/01/15 11:16:08 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	log_pid(char c, int option)
{
	static char	client_pid[] = {0, 0, 0, 0, 0, 0};
	static int	i = 0;

	if (option == 0)
	{
		client_pid[i++] = c;
	}
	else if (option == 1)
	{
		i = 0;
		if (kill(ft_atoi(client_pid), SIGUSR1) == -1)
			ft_error("Couldn't send SIGUSR1 signal.\n");
		ft_bzero(client_pid, 6);
	}
}

void	ft_write(int toput)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				ismsg = 0;

	c |= (toput << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			if (ismsg)
			{
				ft_putchar('\n');
				log_pid(0, 1);
			}
			ismsg = !ismsg;
		}
		else if (!ismsg)
			log_pid(c, 0);
		else
			ft_putchar(c);
		i = 0;
		c = 0;
	}
}

void	sig(int citrus)
{
	if (citrus == SIGUSR1)
		ft_write(0);
	else if (citrus == SIGUSR2)
		ft_write(1);
}

void	get_signal(void)
{
	if (signal(SIGUSR1, sig) == SIG_ERR)
		ft_error("SIGUSR1 signal failed.\n");
	if (signal(SIGUSR2, sig) == SIG_ERR)
		ft_error("SIGUSR2 signal failed.\n");
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		ft_error("Bad usage. No Arguments needed.");
	ministart();
	get_signal();
	signal(SIGWINCH, SIG_IGN);
	while (1)
		pause();
	argv = 0;
	return (0);
}
