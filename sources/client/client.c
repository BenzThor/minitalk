/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:34:29 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/13 12:46:00 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_quit()
{

}

void	ft_check_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		ft_quit();
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit)
			return 1;
	}
}


int	main(int argc, char **argv)
{
	ft_check_arguments(argc, argv);
	ft_isdigit();
}
