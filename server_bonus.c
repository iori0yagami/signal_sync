/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:22:49 by sabadri           #+#    #+#             */
/*   Updated: 2025/03/06 14:46:02 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	output_character(int *index, int *buffer, char *arr)
{
	int	j;

	j = 0;
	if (*index != *buffer)
		return ;
	while (j < *buffer)
	{
		write(1, &arr[j], 1);
		j++;
	}
	*index = 0;
	*buffer = 0;
}

void	reset_buffer_for_new_client(int *bit, int *index, int *buffer,
		char *arr)
{
	*bit = 0;
	*index = 0;
	*buffer = 0;
	arr[*index] = 0;
}

void	process_received_signal(int signal, siginfo_t *info)
{
	static int	bit;
	static int	index;
	static char	arr[4];
	static int	last_client_id;
	static int	buffer;

	if (info->si_pid != last_client_id)
		reset_buffer_for_new_client(&bit, &index, &buffer, arr);
	arr[index] = ((arr[index] << 1) | (signal == SIGUSR1));
	if (++bit == 8)
	{
		buffer = count_buffer_size(arr[index], buffer);
		index++;
		output_character(&index, &buffer, arr);
		bit = 0;
		arr[index] = 0;
	}
	last_client_id = info->si_pid;
}

static void	signal_handler(int signal, siginfo_t *info, void *oldact)
{
	(void)(oldact);
	process_received_signal(signal, info);
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_RESTART | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 1)
	{
		ft_putstr_fd("Server does not take parameters !\n", 2);
		return (-1);
	}
	draw();
	ft_putstr_fd("                 PID :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("                by : Sabadri", 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
