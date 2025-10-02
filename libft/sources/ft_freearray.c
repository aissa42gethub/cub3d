/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:05 by azsaleh           #+#    #+#             */
/*   Updated: 2025/08/31 23:12:37 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//frees all allocated memory from 2d array

#include "libft.h"
#include <stdio.h>

void	ft_freearray(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i++] = NULL;
	}
	free(array);
	array = NULL;
}
