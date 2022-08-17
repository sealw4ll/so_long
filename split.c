/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:48:58 by wting             #+#    #+#             */
/*   Updated: 2022/08/17 14:32:33 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	a = malloc(sizeof(char) * len + 1);
	if (!a)
		return (NULL);
	a[0] = '\0';
	if (start <= len)
	{
		while (i < len)
		{
			a[i] = s[start + i];
			++i;
		}
	}
	a[i] = '\0';
	return (a);
}

static int	countlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s)
	{
		++count;
		++s;
	}
	return (count);
}

static int	getwords(char const *s, char c, t_vars *vars)
{
	while (*s)
	{
		if (*s != c)
		{
			++vars->height;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (vars->height);
}

char	**ft_split(char const *s, char c, t_vars *vars)
{
	char	**a;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (getwords(s, c, vars) + 1));
	if (!a)
		return (NULL);
	vars->width = countlen(s, c);
	while (*s)
	{
		if (countlen(s, c) != 0)
		{
			if (vars->width != countlen(s, c))
				vars->mapvalid = 1;
			a[i] = ft_substr(s, 0, countlen(s, c));
			s += countlen(s, c);
			++i;
		}
		else
			++s;
	}
	a[i] = NULL;
	return (a);
}
