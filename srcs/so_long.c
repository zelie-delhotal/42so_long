/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:51 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/18 15:49:54 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*window;
	void	*image;
	char	**map;

	if (ac < 2)
		exit(1);
	map = map_parser(av[1]);
	if (map == NULL)
		exit(0);
	mlx = mlx_init();
	int	width;
	int	height;
	image = mlx_xpm_file_to_image(mlx, "images/test_square.xpm", &width, &height);
	window = mlx_new_window(mlx, 500, 500, "Logi Run");
	mlx_put_image_to_window(mlx, image, window, 0 , 0);
	mlx_loop(mlx);
}
