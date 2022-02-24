/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:08:35 by jhong             #+#    #+#             */
/*   Updated: 2022/02/24 16:37:28 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	buffer = 0;
	static int	bit = 0;
	static int	server_pid = 0;

	(void)context;
	if (server_pid != info->si_pid)
	{
		server_pid = info->si_pid;
		buffer = 0;
		bit = 0;
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	if (signum == SIGUSR1)
		buffer |= 1;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(buffer, STDOUT_FILENO);
		buffer = 0;
		bit = 0;
		return ;
	}
	buffer <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	s_sigaction.sa_sigaction = handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
}
