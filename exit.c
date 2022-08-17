/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:11:04 by wting             #+#    #+#             */
/*   Updated: 2022/08/17 16:38:51 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_free(t_vars *vars)
{
	while (vars->height >= 0)
	{
		free(vars->map[vars->height]);
		--vars->height;
	}
	free(vars->map);
	write(1, "\ngame exit\n\n", 11);
	exit(0);
	return (0);
}

int	exit_map(t_vars *vars)
{
	while (vars->height >= 0)
	{
		free(vars->map[vars->height]);
		--vars->height;
	}
	free(vars->map);
	write(1, "error\nmap error\n", 14);
	exit(0);
	return (0);
}

int	exit_win(t_vars *vars)
{
	while (vars->height >= 0)
	{
		free(vars->map[vars->height]);
		--vars->height;
	}
	free(vars->map);
	write(1, "\n\nYOU WIN!!!!\n\n\n", 16);
	exit(0);
	return (0);
}

int	exit_lose(t_vars *vars)
{
	while (vars->height >= 0)
	{
		free(vars->map[vars->height]);
		--vars->height;
	}
	free(vars->map);
	write(1, "\n\nYOU SUCK!!!!\n\n\n", 17);
	exit(0);
	return (0);
}
