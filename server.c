/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:07:34 by akaratas          #+#    #+#             */
/*   Updated: 2024/02/25 18:11:54 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

void	signal_handler(int signalno)
{
	static char	create_byte;
	static int	bit_counter;

	if (signalno == SIGUSR1)
		create_byte = (create_byte << 1) | 1;
	else if (signalno == SIGUSR2)
		create_byte = (create_byte << 1);
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &create_byte, 1);
		create_byte = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
