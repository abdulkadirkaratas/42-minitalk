/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:07:42 by akaratas          #+#    #+#             */
/*   Updated: 2024/02/25 18:12:04 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

void	signal_sender(char c, int server_pid)
{
	int		bit_shift;
	char	left_bit;

	bit_shift = 7;
	while (bit_shift >= 0)
	{
		left_bit = (c >> bit_shift) & 1;
		if (left_bit == 1)
			kill(server_pid, SIGUSR1);
		else if (left_bit == 0)
			kill(server_pid, SIGUSR2);
		usleep(142);
		bit_shift--;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;
	int		i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		i = 0;
		while (str[i] != 0)
		{
			signal_sender(str[i], server_pid);
			i++;
		}
	}
	else
		write(1, "The client must takes two parameters!\n", 39);
	return (0);
}
