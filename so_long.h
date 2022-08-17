/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:46:49 by wting             #+#    #+#             */
/*   Updated: 2022/08/17 16:41:35 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>	
# include "./printf/ft_printf.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;

	int		man_x;
	int		man_y;
	char	*man_path;
	void	*man_img;

	int		enemy_x;
	int		enemy_y;
	char	*enemy_path;
	void	*enemy_img;
	int		enemy_count;

	int		exit_x;
	int		exit_y;

	int		img_size;

	char	*bg_path;
	void	*bg_img;

	char	*coin_path;
	void	*coin_img;

	char	*wall_path;
	void	*wall_img;

	char	*exit_path;
	void	*exit_img;

	int		width;
	int		height;

	char	**map;
	int		mapvalid;

	int		randomizer;
	int		animation_count;

	int		tmpx;
	int		tmpy;

	int		ccount;
	int		ccollected;

	int		move_count;
}	t_vars;

int		image_loop(t_vars *vars);

char	**ft_split(char const *s, char c, t_vars *vars);
char	*ft_itoa(int n);

int		init_map(char *filename, t_vars *vars);
int		exit_free(t_vars *vars);
int		exit_map(t_vars *vars);
int		exit_win(t_vars *vars);
int		exit_lose(t_vars *vars);

void	up(t_vars *vars);
void	down(t_vars *vars);
void	left(t_vars *vars);
void	right(t_vars *vars);

#endif