/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:31:01 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/16 12:47:55 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* include libraries */
# include <signal.h>
# include "../libraries/libft/libft.h"

# define ERR_MSG	"You didn't put the right arguments - a pid and a message."
# define ERR_MSG2	"The process ID should only consist of numbers."
# define PID_ERR	"You didn't enter a valid Process ID"

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

#endif