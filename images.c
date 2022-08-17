/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:50:06 by wting             #+#    #+#             */
/*   Updated: 2022/08/18 01:13:36 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_loop(t_vars *vars)
{
	if (vars->map[vars->enemy_y / 64 - 1][vars->enemy_x / 64] != '1' \
	&& vars->randomizer % 4 == 0)
		vars->enemy_y -= 64;
	else if (vars->map[vars->enemy_y / 64 + 1][vars->enemy_x / 64] != '1' \
	&& vars->randomizer % 4 == 1)
		vars->enemy_y += 64;
	else if (vars->map[vars->enemy_y / 64][vars->enemy_x / 64 - 1] != '1' \
	&& vars->randomizer % 4 == 2)
		vars->enemy_x -= 64;
	else if (vars->map[vars->enemy_y / 64][vars->enemy_x / 64 + 1] != '1' \
	&& vars->randomizer % 4 == 3)
		vars->enemy_x += 64;
	if (vars->enemy_x == vars->man_x && vars->enemy_y == vars->man_y)
		exit_lose(vars);
}

void	man_loop(t_vars *vars)
{
	if (vars->animation_count % 32 < 16)
	{
		vars->man_path = "./xpm/mantine.xpm";
		vars->enemy_path = "./xpm/tentacruel.xpm";
	}
	if (vars->animation_count % 32 >= 16)
	{
		vars->man_path = "./xpm/mantine2.xpm";
		vars->enemy_path = "./xpm/tentacruel2.xpm";
	}
	vars->man_img = mlx_xpm_file_to_image(vars->mlx, vars->man_path, \
			&vars->img_size, &vars->img_size);
	if (vars->enemy_count == 1)
	vars->enemy_img = mlx_xpm_file_to_image(vars->mlx, vars->enemy_path, \
			&vars->img_size, &vars->img_size);
}

void	asset_loop(t_vars *vars)
{
	vars->tmpx = 0;
	vars->tmpy = 0;
	while (vars->tmpy < vars->height)
	{
		vars->tmpx = 0;
		while (vars->tmpx < vars->width)
		{
			if (vars->map[vars->tmpy][vars->tmpx] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, \
				vars->tmpx * 64, vars->tmpy * 64);
			if (vars->map[vars->tmpy][vars->tmpx] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->coin_img, \
				vars->tmpx * 64, vars->tmpy * 64);
			if (vars->map[vars->tmpy][vars->tmpx] == 'E' && \
				vars->ccount == vars->ccollected)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img, \
				vars->tmpx * 64, vars->tmpy * 64);
			++vars->tmpx;
		}
		++vars->tmpy;
	}
}

int	background_loop(t_vars *vars)
{
	vars->tmpx = 0;
	vars->tmpy = 0;
	while (vars->tmpy < vars->height)
	{
		vars->tmpx = 0;
		while (vars->tmpx < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, \
				vars->tmpx * 64, vars->tmpy * 64);
			++vars->tmpx;
		}
		++vars->tmpy;
	}
	return (0);
}

int	image_loop(t_vars *vars)
{
	char	*count;

	man_loop(vars);
	background_loop(vars);
	asset_loop(vars);
	vars->randomizer = (vars->randomizer + vars->randomizer * 1738) % 727;
	if (vars->enemy_count == 1 && vars->animation_count % 4 == 0)
		enemy_loop(vars);
	mlx_string_put(vars->mlx, vars->win, 5, 0, 16777215, "Movemint counter:");
	count = ft_itoa(vars->move_count);
	mlx_string_put(vars->mlx, vars->win, 175, 0, 16777215, count);
	free (count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->man_img, \
		vars->man_x, vars->man_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_img, \
		vars->enemy_x, vars->enemy_y);
	++vars->animation_count;
	return (0);
}
