/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:05 by jhong             #+#    #+#             */
/*   Updated: 2022/02/24 16:47:30 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_8bit(int server_pid, char c)
{
	int	bit;
	int	cnt;

	cnt = 8;
	while (cnt--)
	{
		bit = (c >> cnt) & 1;
		if (bit)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(250);
	}
}

void	send_message(int server_pid, char *message)
{
	while (*message)
	{
		send_8bit(server_pid, *message);
		message++;
	}
}

int	main(int argc, char *argv[])
{
	char	*message;
	int		server_pid;

	if (argc != 3 || !ft_isdigit(argv[1]))
	{
		ft_putstr_fd("Invalid Argument. Re-enter.\n", STDERR_FILENO);
		return (0);
	}
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd("Empty String. Re-enter.\n", STDERR_FILENO);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	if (server_pid <= 100 || server_pid >= 4194304)
	{
		ft_putstr_fd("Invalid PID. Re-enter.\n", STDERR_FILENO);
		return (0);
	}
	ft_putstr_fd("client pid: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', 1);
	send_message(server_pid, message);
}
