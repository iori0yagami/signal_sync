/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:49:55 by sabadri           #+#    #+#             */
/*   Updated: 2025/03/06 13:33:07 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	draw(void)
{
	ft_putstr_fd("       .       o          ' _|_              \n", 1);
	ft_putstr_fd("          ** .        '      |           o   \n", 1);
	ft_putstr_fd("                                             \n", 1);
	ft_putstr_fd("  .-.                       .-.                   \n", 1);
	ft_putstr_fd(" (   )      '     .-.      (   )':.     o     \n", 1);
	ft_putstr_fd("  `-'            ( (        `-'   '::._         \n", 1);
	ft_putstr_fd("                  `-'               '._)      . \n", 1);
	ft_putstr_fd("             o                     .  o         \n", 1);
	ft_putstr_fd("        '         . .             '   *          \n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("                  /\\ _____/\\              \n", 1);
	ft_putstr_fd("                 /  o   o  \\          \n", 1);
	ft_putstr_fd("                ( ==  ^  == )           \n", 1);
	ft_putstr_fd("                 )         (                 \n", 1);
	ft_putstr_fd("                (           )                \n", 1);
	ft_putstr_fd("               ( (  )   (  ) )               \n", 1);
	ft_putstr_fd("              (__(__)___(__)__)               \n", 1);
}

int	count_buffer_size(unsigned char c, int buffer)
{
	if (buffer != 0)
		return (buffer);
	if (c >= 240)
		return (4);
	if (c >= 224)
		return (3);
	if (c >= 192)
		return (2);
	return (1);
}
