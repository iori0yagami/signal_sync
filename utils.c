/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:30:21 by sabadri           #+#    #+#             */
/*   Updated: 2025/03/06 13:07:40 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_out(unsigned long res, int sign)
{
	if (res >= 9223372036854775807 && sign == 1)
		return (-1);
	if (res > 9223372036854775807)
		return (0);
	return (2);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		if (get_out(result, sign) != 2)
			return (get_out(result, sign));
		i++;
	}
	return (result * sign);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (fd >= 0 && str)
	{
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
	return ;
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > -1)
	{
		write(fd, &c, 1);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			digit = n + '0';
			write(fd, &digit, 1);
		}
	}
}
