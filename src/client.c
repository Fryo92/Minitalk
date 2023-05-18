/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:42 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 13:41:49 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bool = 0;

void	handle_client(int sig, siginfo_t *info, void *ptr)
{
	(void)info;
	(void)ptr;
	if (sig == SIGUSR2)
		g_bool = 1;
}

void	print_c(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c & 1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_bool)
			pause();
		g_bool = 0;
		bits++;
	}
}

int	check_pid(char *str)
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

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	i = 0;
	if (ac != 3 || check_pid(av[1]) == 0)
		ft_printf("Wrong format ! Try ./client <PID> <string>");
	else
	{
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sa.sa_sigaction = &handle_client;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pid = atoi(av[1]);
		while (av[2][i])
		{
			print_c(pid, av[2][i]);
			i++;
		}
		print_c(pid, '\n');
	}	
}
