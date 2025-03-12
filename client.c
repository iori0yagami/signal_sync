/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:20:38 by sabadri           #+#    #+#             */
/*   Updated: 2025/03/07 21:17:13 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_flag;

void	handle_signal(int signal)
{
	(void)signal;
	g_flag = 1;
}

void	send_char(pid_t id, char c)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		g_flag = 0;
		if ((c >> bits) & 1)
		{
			if (kill(id, SIGUSR1) < 0)
				exit(123);
		}
		else
		{
			if (kill(id, SIGUSR2) < 0)
				exit(124);
		}
		while (!g_flag)
			;
		bits--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

static int	parsing(int ac, char *str)
{
	if (ac != 3)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				id;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	if (sigemptyset(&sa.sa_mask))
        return (1);
	sigaction(SIGUSR1, &sa, NULL);
	if (!parsing(ac, av[1]))
	{
		ft_putstr_fd("invalid count or id !\n", 2);
		return (1);
	}
	id = ft_atoi(av[1]);
	send_message(id, av[2]);
	return (0);
}
