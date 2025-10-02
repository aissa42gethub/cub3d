/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:28:36 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:28:37 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//set a block of memory to a specific value

#include "libft.h"

//cast the pointer to unsigned char
//in iteration, set its value to the specified c value
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len)
	{
		*p++ = (unsigned char)c;
		len--;
	}
	return (b);
}
/*
//cc -Wall -Wextra -Werror ft_memset.c libft.a -o ft_memset.out
//./ft_memset.out
//fill array with 'A' using memset
//then print the array to confirm result
#include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned long	i;
	char			lib[5];
	char			ft[5];

	memset(lib, 'x', sizeof(lib));
	i = 0;
	while (i < sizeof(lib))
	{
		printf("[lib]   %lu:'%c'\n", i, lib[i]);
		i++;
	}
	printf("\n");
	//[lib]   0:'x'
	//[lib]   1:'x'
	//[lib]   2:'x'
	//[lib]   3:'x'
	//[lib]   4:'x'

	ft_memset(ft, 'x', sizeof(ft));
	i = 0;
	while (i < sizeof(ft))
	{
		printf("[ft]    %lu:'%c'\n", i, ft[i]);
		i++;
	}
	printf("\n");
	//[ft]    0:'x'
	//[ft]    1:'x'
	//[ft]    2:'x'
	//[ft]    3:'x'
	//[ft]    4:'x'

	return (0);
}
*/