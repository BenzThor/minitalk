/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:31:01 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/16 18:15:50 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* include libraries */
# include <signal.h>
# include "../libraries/libft/libft.h"

// error messages
# define ERR_MSG	"You didn't put the right arguments - a pid and a message."
# define ERR_MSG2	"The process ID should only consist of numbers."
# define PID_ERR	"You didn't enter a valid Process ID"

// struct to store all variables needed for the server, that shouldn't change
typedef struct s_server
{
	unsigned int		get_len;
	unsigned int		i_len;
	unsigned int		len;
	unsigned int		i_mess;
	unsigned char		byte;
	pid_t				cpid;
	char				*str;
}	t_server;

/* functions - server */
// handles the incoming signals (SIGUSR1 & SIGUSR2), also gets info on sender
void	ft_handler_s(int signum, siginfo_t *info, void *no);
// receives the length of the str to be received by the client
void	ft_get_len(int signum, t_server *server);
// "rebuilds" the str send by the client
void	ft_interpret_message(int signum, t_server *server);
// initializes the struct's variables to zero
void	ft_init(t_server *server, pid_t cpid);

/* functions - client */
// checks the argv elements for correctness (pid = digits; 3 arguments as inp)
void	ft_check_arguments(int argc, char **argv);
// sends the length of the str that is to be send to the server;
void	ft_send_len(unsigned int len, int pid);
// sends the message to the server - bit by bit and waits for its acknowldgment
void	ft_send_message(unsigned char bit, int pid);
// to handle the reception signal that is send by the server
void	ft_handler_c(int signum);

#endif
