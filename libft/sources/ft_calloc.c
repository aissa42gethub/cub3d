/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:27:39 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:27:40 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//allocate memory for an array of elements and initialize all bytes to zero

#include "libft.h"

//allocate memory using malloc
//check if malloc succeeded. return pointer immediately if not
//initialize allocated memory to zero
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(0);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (count > 4294967295 / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
// cc -Wall -Wextra -Werror ft_calloc.c libft.a -o ft_calloc.out
//./ft_calloc.out
//allocate memory with calloc
//check if calloc succeeded
//print the array. all values should be 0
//free allocated memory
#include <stdio.h>
int	main(void)
{
	int	*lib;
	int	*ft;
	int	count = 5;
	int	i;

	lib = (int *)calloc(count, sizeof(int));
	if (lib == NULL)
		return 1;
	i = 0;
	while (i < count)
	{
		printf("lib[%d] = %d\n", i, lib[i]);
		i++;
	}
	free(lib);
	printf("\n");
	//lib[0] = 0
	//lib[1] = 0
	//lib[2] = 0
	//lib[3] = 0
	//lib[4] = 0

	ft = (int *)ft_calloc(count, sizeof(int));
	if (ft == NULL)
		return 1;
	i = 0;
	while (i < count)
	{
		printf("ft[%d] = %d\n", i, ft[i]);
		i++;
	}
	free(ft);
	printf("\n");
	//ft[0] = 0
	//ft[1] = 0
	//ft[2] = 0
	//ft[3] = 0
	//ft[4] = 0

	return (0);
}
*/