/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:34:29 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/14 14:35:33 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_signal(unsigned char **argv, int pid)
{
	int				i;
	int				n;
	unsigned char	bit;

	i = 0;
	while (argv[2][i])
	{
		n = 9;
		while (--n > 0)
		{
			bit >>= n;
			if (bit % 2 == 0)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
		}
		usleep(42);
	}
}

void	ft_check_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd(ERR_MSG, 2);
		exit (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd(ERR_MSG2, 2);
			exit (0);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	ft_check_arguments(argc, argv);
	ft_send_signal(argv, ft_atoi(argv[1]));
	return (0);
}
