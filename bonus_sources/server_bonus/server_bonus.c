/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:25 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/16 14:40:03 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk_bonus.h"

void	ft_interpret_message(int signum, t_server *server)
{
	if (!server->str)
	{
		server->str = (char *)malloc((sizeof(char) * (server->len + 1)));
		if (!server->str)
			return ;
	}
	if (signum == SIGUSR2)
		server->byte += 128;
	server->i_mess++;
	if (server->i_mess % 8 == 0)
	{
		server->str[(server->i_mess / 8) - 1] = server->byte;
		server->byte = 0;
	}
	else
		server->byte = server->byte >> 1;
	if (server->i_mess == server->len * 8)
	{
		server->str[server->len] = '\0';
		ft_putstr_fd(server->str, 1);
		free(server->str);
		server->str = NULL;
		server->len = 0;
		server->i_mess = 0;
	}
}

void	ft_get_len(int signum, t_server *server)
{
	if (signum == SIGUSR2)
		server->get_len += 2147483648;
	server->i_len++;
	if (server->i_len == 32)
	{
		server->len = server->get_len;
		server->get_len = 0;
		server->i_len = 0;
	}
	else
		server->get_len = server->get_len >> 1;
}

void	ft_handler_s(int signum, siginfo_t *info, void *no)
{
	static t_server	server;

	no = NULL;
	server.cpid = info->si_pid;
	if (server.len == 0)
		ft_get_len(signum, &server);
	else
		ft_interpret_message(signum, &server);
	kill(server.cpid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("The PID is: %d\n", getpid());
	act.sa_sigaction = ft_handler_s;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
