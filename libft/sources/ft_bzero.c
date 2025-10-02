/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:15:56 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 19:14:01 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//set all bytes in a block of memory to zero

#include "libft.h"

//cast argument to a new pointer
//iterate through argument range and reset its value
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
//cc -Wall -Wextra -Werror ft_bzero.c libft.a -o ft_bzero.out
//./ft_bzero.out
#include <stdio.h>
#include <strings.h>
int	main(void)
{
	unsigned long	i;
	char		lib_a[3] = "abc";
	char		ft_a[3] = "abc";
	char		lib_b[0];
	char		ft_b[0];

	i = 0;
	while (i < sizeof(lib_a))
	{
		printf("[lib pre]    i:%lu   v:'%c'\n", i, lib_a[i]);
		i++;
	}
	bzero(lib_a, sizeof(lib_a));
	i = 0;
	while (i < sizeof(lib_a))
	{
		printf("[lib post]   i:%lu   v:'%c'\n", i, lib_a[i]);
		i++;
	}
	printf("\n");
	//[lib pre]    i:0   v:'a'
	//[lib pre]    i:1   v:'b'
	//[lib pre]    i:2   v:'c'
	//[lib post]   i:0   v:''
	//[lib post]   i:1   v:''
	//[lib post]   i:2   v:''

	i = 0;
	while (i < sizeof(ft_a))
	{
		printf("[ft pre]     i:%lu   v:'%c'\n", i, ft_a[i]);
		i++;
	}
	ft_bzero(ft_a, sizeof(ft_a));
	i = 0;
	while (i < sizeof(ft_a))
	{
		printf("[ft post]    i:%lu   v:'%c'\n", i, ft_a[i]);
		i++;
	}
	printf("\n");
	//[ft pre]     i:0   v:'a'
	//[ft pre]     i:1   v:'b'
	//[ft pre]     i:2   v:'c'
	//[ft post]    i:0   v:''
	//[ft post]    i:1   v:''
	//[ft post]    i:2   v:''

	i = 0;
	while (i < sizeof(lib_b))
	{
		printf("[lib pre]    i:%lu   v:'%c'\n", i, lib_b[i]);
		i++;
	}
	bzero(lib_b, sizeof(lib_b));
	i = 0;
	while (i < sizeof(lib_b))
	{
		printf("[lib post]   i:%lu   v:'%c'\n", i, lib_b[i]);
		i++;
	}
	printf("\n");
	//

	i = 0;
	while (i < sizeof(ft_b))
	{
		printf("[ft pre]     i:%lu   v:'%c'\n", i, ft_b[i]);
		i++;
	}
	ft_bzero(ft_b, sizeof(ft_b));
	i = 0;
	while (i < sizeof(ft_b))
	{
		printf("[ft post]    i:%lu   v:'%c'\n", i, ft_b[i]);
		i++;
	}
	printf("\n");
	//

	return (0);
}
*/