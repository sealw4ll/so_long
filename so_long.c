/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:00:45 by wting             #+#    #+#             */
/*   Updated: 2022/08/17 19:20:47 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_free(vars);
	else if (keycode == 13 && \
		vars->map[vars->man_y / 64 - 1][vars->man_x / 64] != '1')
		up(vars);
	else if (keycode == 1 && \
		vars->map[vars->man_y / 64 + 1][vars->man_x / 64] != '1')
		down(vars);
	else if (keycode == 0 && \
		vars->map[vars->man_y / 64][vars->man_x / 64 - 1] != '1')
		left(vars);
	else if (keycode == 2 && \
		vars->map[vars->man_y / 64][vars->man_x / 64 + 1] != '1')
		right(vars);
	if (vars->enemy_x == vars->man_x && vars->enemy_y == vars->man_y)
		exit_lose(vars);
	return (0);
}

void	xpm(t_vars *vars)
{
	vars->bg_path = "./xpm/ocean.xpm";
	vars->bg_img = mlx_xpm_file_to_image(vars->mlx, vars->bg_path, \
			&vars->img_size, &vars->img_size);
	vars->coin_path = "./xpm/berry.xpm";
	vars->coin_img = mlx_xpm_file_to_image(vars->mlx, vars->coin_path, \
			&vars->img_size, &vars->img_size);
	vars->wall_path = "./xpm/wall.xpm";
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, vars->wall_path, \
			&vars->img_size, &vars->img_size);
	vars->exit_path = "./xpm/exit.xpm";
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx, vars->exit_path, \
			&vars->img_size, &vars->img_size);
}

int	init_vars(char *filename, t_vars *vars)
{
	vars->man_x = 0;
	vars->man_y = 0;
	vars->mapvalid = 0;
	vars->ccollected = 0;
	vars->ccount = 0;
	vars->move_count = 0;
	vars->height = 0;
	vars->width = 0;
	vars->animation_count = 0;
	vars->enemy_count = 0;
	xpm(vars);
	init_map(filename, vars);
	vars->randomizer = vars->ccount + vars->height + vars->width;
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	vars.mlx = mlx_init();
	init_vars(argv[1], &vars);
	vars.win = mlx_new_window(vars.mlx, vars.width * 64, \
		vars.height * 64, "so_long");
	mlx_hook(vars.win, 17, (1L << 0), exit_free, &vars);
	mlx_key_hook(vars.win, input, &vars);
	mlx_loop_hook(vars.mlx, image_loop, &vars);
	mlx_loop(vars.mlx);
}
