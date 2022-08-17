/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:09:16 by wting             #+#    #+#             */
/*   Updated: 2022/08/17 19:14:28 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_check(t_vars *vars)
{
	int	j;
	int	i;

	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->map[j][i] != 'P' && vars->map[j][i] != '1' && \
			vars->map[j][i] != 'C' && vars->map[j][i] != '0' && \
			vars->map[j][i] != 'E' && vars->map[j][i] != 'A')
				vars->mapvalid = 1;
		}
	}
}

void	wall_check(t_vars *vars)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (vars->map[0][i])
	{
		if (vars->map[0][i] != '1')
			vars->mapvalid = 1;
		++i;
	}
	while (j < vars->height - 1)
	{
		if (vars->map[j][0] != '1' || vars->map[j][vars->width - 1] != '1')
			vars->mapvalid = 1;
		++j;
	}
	i = 0;
	while (vars->map[vars->height - 1][i])
	{
		if (vars->map[vars->height - 1][i] != '1')
			vars->mapvalid = 1;
		++i;
	}
}

void	charpos_helper(int *checkp, int *checka, int *checke, t_vars *vars)
{
	if (vars->map[vars->tmpy][vars->tmpx] == 'P')
	{
		vars->man_x = vars->tmpx * 64;
		vars->man_y = vars->tmpy * 64;
		++*checkp;
	}
	if (vars->map[vars->tmpy][vars->tmpx] == 'A')
	{
		vars->enemy_x = vars->tmpx * 64;
		vars->enemy_y = vars->tmpy * 64;
		++*checka;
	}
	if (vars->map[vars->tmpy][vars->tmpx] == 'E')
	{
		vars->exit_x = vars->tmpx * 64;
		vars->exit_y = vars->tmpy * 64;
		++*checke;
	}
	if (vars->map[vars->tmpy][vars->tmpx] == 'C')
		++vars->ccount;
}

void	charpos(t_vars *vars)
{
	int	checkp;
	int	checka;
	int	checke;

	vars->tmpy = -1;
	checkp = 0;
	checka = 0;
	checke = 0;
	while (++vars->tmpy < vars->height)
	{
		vars->tmpx = -1;
		while (++vars->tmpx < vars->width)
		{
			charpos_helper(&checkp, &checka, &checke, vars);
		}
	}
	if (checkp != 1 || checka > 1 || checke != 1 || vars->ccount < 1)
		vars->mapvalid = 1;
	vars->enemy_count = checka;
}

int	init_map(char *filename, t_vars *vars)
{
	int		fd;
	char	*temp;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\nmap fd error\n", 19);
		exit(0);
	}
	temp = malloc(sizeof(char) * (10000 + 1));
	i = read(fd, temp, 10000);
	temp[i] = 0;
	vars->map = ft_split(temp, '\n', vars);
	free(temp);
	if (vars->mapvalid == 1)
		exit_map(vars);
	all_check(vars);
	wall_check(vars);
	charpos(vars);
	if (vars->mapvalid == 1)
		exit_map(vars);
	return (0);
}
