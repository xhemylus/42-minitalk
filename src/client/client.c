/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:16:57 by abollen           #+#    #+#             */
/*   Updated: 2022/01/21 10:17:29 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		if (kill(pid, SIGUSR1) == -1)
			ft_error("Couldn't send SIGUSR1 signal.\n");
	if (bit == 1)
		if (kill(pid, SIGUSR2) == -1)
			ft_error("Couldn't send SIGUSR2 signal.\n");
}

void	convertchar(int pid, char to_send)
{
	char	c;
	int		bit;

	c = 0;
	while (c < 8)
	{
		bit = (to_send >> c++) & 1;
		usleep(100);
		send_bit(pid, bit);
	}
}

void	get_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		convertchar(pid, str[i]);
		i++;
	}
	convertchar(pid, 0);
}

void	get_signal(void)
{
	if (signal(SIGUSR1, receipt) == SIG_ERR)
		ft_error("SIGUSR1 signal failed.\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*pid_client;

	if (argc != 3)
		ft_error("usage : ./client [PID] [str]\n");
	if (!ft_isnum(argv[1]))
		ft_error("Error : PID must be a number.\n");
	pid = ft_atoi(argv[1]);
	pid_client = ft_itoa(getpid());
	if (!pid_client)
		return (0);
	if (pid <= 1)
		ft_error("Error : Invalid PID.\n");
	get_char(pid, pid_client);
	free(pid_client);
	get_signal();
	get_char(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
