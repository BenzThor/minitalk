/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:25 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/15 19:38:06 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static unsigned int	len;

void	ft_interpret_message(int signum)
{
	static unsigned char	byte;
	static unsigned int		i;
	static char				*str;

	if (!str)
	{
		str = (char *)malloc((sizeof(char) * (len + 1)));
		if (!str)
			return ;
	}
	if (signum == SIGUSR2)
		byte += 128;
	i++;
	if (i % 8 == 0)
	{
		str[(i / 8) - 1] = byte;
		byte = 0;
	}
	else
		byte = byte >> 1;
	if (i == len * 8)
	{
		str[len] = '\0';
		ft_putstr_fd(str, 1);
		free(str);
    	str = NULL;
    	len = 0;
    	i = 0;
	}
}

void	ft_get_len(int signum)
{
	static unsigned int		get_len;
	static int				i;

	if (signum == SIGUSR2)
		get_len += 2147483648;
	i++;
	if (i == 32)
	{
		len = get_len;
		get_len = 0;
		i = 0;
	}
	else
		get_len = get_len >> 1;
}

void	ft_handler(int signum)
{
	if (len == 0)
		ft_get_len(signum);
	else
		ft_interpret_message(signum);
}

int	main(void)
{
	len = 0;
	ft_printf("The PID is: %d\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
