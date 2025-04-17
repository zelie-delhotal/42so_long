/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:51 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/17 18:28:13 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*window;
	char	**map;

	if (ac < 2)
		exit(1);
	map = map_parser(av[1]);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "Logi Run");
	mlx_loop(mlx);
}
