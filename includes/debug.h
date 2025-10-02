/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:11:07 by azrulsaleh        #+#    #+#             */
/*   Updated: 2025/09/01 16:45:46 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

//debug
void	debug_struct(t_cub *cub);

//debug_map
void	print_map_values(t_map map);
void	debug_map_optimized(t_map map);
void	debug_map_floodfill(char **map, bool is_invalid);
void	debug_map_final(t_map map);

#endif
