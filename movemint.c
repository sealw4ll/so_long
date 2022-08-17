/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:37:16 by wting             #+#    #+#             */
/*   Updated: 2022/08/17 16:40:59 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_vars *vars)
{
	vars->man_y -= 64;
	if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'E' && \
		vars->ccount == vars->ccollected)
		exit_win(vars);
	else if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'C')
	{
		++vars->ccollected;
		vars->map[vars->man_y / 64][vars->man_x / 64] = '0';
	}
	++vars->move_count;
}

void	down(t_vars *vars)
{
	vars->man_y += 64;
	if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'E' && \
		vars->ccount == vars->ccollected)
		exit_win(vars);
	else if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'C')
	{
		++vars->ccollected;
		vars->map[vars->man_y / 64][vars->man_x / 64] = '0';
	}
	++vars->move_count;
}

void	left(t_vars *vars)
{
	vars->man_x -= 64;
	if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'E' && \
		vars->ccount == vars->ccollected)
		exit_win(vars);
	else if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'C')
	{
		++vars->ccollected;
		vars->map[vars->man_y / 64][vars->man_x / 64] = '0';
	}
	++vars->move_count;
}

void	right(t_vars *vars)
{
	vars->man_x += 64;
	if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'E' && \
		vars->ccount == vars->ccollected)
		exit_win(vars);
	else if (vars->map[vars->man_y / 64][vars->man_x / 64] == 'C')
	{
		++vars->ccollected;
		vars->map[vars->man_y / 64][vars->man_x / 64] = '0';
	}
	++vars->move_count;
}
