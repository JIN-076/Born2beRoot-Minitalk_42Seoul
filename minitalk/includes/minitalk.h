/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:46:32 by jhong             #+#    #+#             */
/*   Updated: 2022/02/24 16:31:35 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putchar_fd(char c, int fd);;
void	ft_print_putnbr(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);

int		ft_isspace(const char *str);
int		ft_isdigit(char *str);
int		ft_atoi(const char *str);

void	send_8bit(int pid, char c);
void	send_message(int pid, char *message);

void	handler(int signum, siginfo_t *info, void *context);

#endif
