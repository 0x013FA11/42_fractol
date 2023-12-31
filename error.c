/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:07:57 by sel-hano          #+#    #+#             */
/*   Updated: 2023/07/27 00:20:42 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int ac, char *av[])
{
	if (ac < 2 || !av[1][0])
	{
		write(1, "ERROR USAGE: ./fractol <name_of_fractal>", 40);
		exit(EXIT_FAILURE);
	}
	else if (ac != 2 && !ft_strcmp("mandelbrot", av[1]))
	{
		write(1, "ERROR: mandelbrot have no params", 32);
		exit(EXIT_FAILURE);
	}
	else if (ac != 2 && !ft_strcmp(av[1], "burningship"))
	{
		write(1, "ERROR USAGE: burningship have no params", 40);
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp("mandelbrot", av[1])
		&& ft_strcmp("julia", av[1])
		&& ft_strcmp("burningship", av[1]))
	{
		write(1, "ERROR USAGE: ./fractol <name_of_fractal>", 40);
		exit(EXIT_FAILURE);
	}
}

void	zoom_out(t_data *init)
{
	init->min_x /= init->zoom_factor;
	init->max_x /= init->zoom_factor;
	init->min_y /= init->zoom_factor;
	init->max_y /= init->zoom_factor;
	init->min_x -= init->center_x;
	init->max_x -= init->center_x;
	init->min_y -= init->center_y;
	init->max_y -= init->center_y;
	init->iterations -= 10;
}

void	zoom_in(t_data *init)
{
	init->min_x += init->center_x;
	init->max_x += init->center_x;
	init->min_y += init->center_y;
	init->max_y += init->center_y;
	init->min_x *= init->zoom_factor;
	init->max_x *= init->zoom_factor;
	init->min_y *= init->zoom_factor;
	init->max_y *= init->zoom_factor;
	init->iterations += 10;
}

char	*mini_atod(t_data *init, const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		init->negative = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		init->result = init->result * 10.0 + (*str - '0');
		str++;
	}
	if (*str != '.')
	{
		write(1, "BAD ARGUMENTS PLEASE WRITE NUMBERS OF TYPE DOUBLE\n", 50);
		exit(EXIT_FAILURE);
	}
	return ((char *)str);
}
