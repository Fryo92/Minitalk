/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:19:04 by abiddane          #+#    #+#             */
/*   Updated: 2023/04/03 14:14:01 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	handle_serv(int sig, siginfo_t *info, void *context)
{
	static t_data	data;

	(void)context;
	if (sig == SIGUSR1)
		data.c |= (1 << data.bits);
	data.bits++;
	if (data.bits == 8)
	{
		ft_putchar_fd(data.c, 1);
		data.bits = 0;
		data.c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (ac != 1)
	{
		ft_printf("Wrong format ! Try ./server\n");
		return (1);
	}
	ft_printf("PID : %d\n", getpid());
	while (ac == 1)
	{
		sa.sa_sigaction = &handle_serv;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
