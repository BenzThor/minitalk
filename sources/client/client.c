/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:34:29 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/15 19:35:21 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	ft_send_signal(unsigned char bit, int pid)
{
	int				i;
	int				n;

	i = 0;
	n = 8;
	while (n-- > 0)
	{
		if (bit & 0x01)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		bit = bit >> 1;
		usleep(400);
	}
}

void	ft_send_len(unsigned int len, int pid)
{
	int				i;
	int				n;

	i = 0;
	n = 32;
	while (n-- > 0)
	{
		if (len & 0x01)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		len = len >> 1;
		usleep(400);
	}
}

void	ft_check_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd(ERR_MSG, 2);
		exit (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd(ERR_MSG2, 2);
			exit (1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char				*str;
	int					i;
	unsigned int		len;
	int					pid;

	ft_check_arguments(argc, argv);
	i = 0;
	str = argv[2];
	len = (unsigned)ft_strlen(str);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
	{
		ft_putstr_fd(PID_ERR, 2);
		exit(1);
	}
	ft_send_len(len, pid);
	while (str[i])
	{
		ft_send_signal(str[i], pid);
		i++;
	}
	return (0);
}
