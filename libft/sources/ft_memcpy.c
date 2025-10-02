/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:28:20 by azsaleh           #+#    #+#             */
/*   Updated: 2025/08/31 19:22:00 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copy a block of memory from one location to another - cannot handle overlap

#include "libft.h"

//if destination and source are null, return null
//cast the void pointers to char pointers for byte-wise copying
//iterate until n is reached, copying content from source to destination
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

//if destination and source are null, return null
//cast the void pointers to char pointers for byte-wise copying
//iterate until n is reached, copying content from source to destination
void	*ft_memcpy_rng(void *dst, const void *src, size_t start, size_t end)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < end)
		d[i++] = s[start++];
	return (dst);
}
/*
//cc -Wall -Wextra -Werror ft_memcpy.c libft.a -o ft_memcpy.out
//./ft_memcpy.out
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src_a[] = "Hello 42!";
	char	src_b[] = "Hi There 42";
	char	src_c[20];
	char	lib_a[20];
	char	ft_a[20];
	char	lib_b[20];
	char	ft_b[20];
	char	lib_c[20];
	char	ft_c[20];

	memcpy(lib_a, src_a, sizeof(src_a));
	printf("[lib]   src_a:'%s'   dest:'%s'\n", src_a, lib_a);
	//[lib]   src_a:'Hello 42!'   dest:'Hello 42!'

	ft_memcpy(ft_a, src_a, sizeof(src_a));
	printf("[ft]    src_a:'%s'   dest:'%s'\n\n", src_a, ft_a);
	//[ft]    src_a:'Hello 42!'   dest:'Hello 42!'

	memcpy(lib_b, src_b, 8);
	// lib_b[8] = '\0';
	printf("[lib]   src_b:'%s'   dest:'%s'\n", src_b, lib_b);
	//[lib]   src_b:'Hi	TherE! 42'   dest:'Hi	TherEx5;k'

	ft_memcpy(ft_b, src_b, 8);
	printf("[ft]    src_b:'%s'   dest:'%s'\n\n", src_b, ft_b);
	//[ft]    src_b:'Hi	TherE! 42'   dest:'Hi	TherE'

	memcpy(lib_c, src_c, 8);
	// lib_b[8] = '\0';
	printf("[lib]   src_c:'%s'   dest:'%s'\n", src_c, lib_c);
	//[lib]   src_b:'Hi	TherE! 42'   dest:'Hi	TherE'

	ft_memcpy(ft_c, src_c, 8);
	printf("[ft]    src_c:'%s'   dest:'%s'\n\n", src_c, ft_c);
	//[ft]    src_b:'Hi	TherE! 42'   dest:'Hi	TherE'

	return (0);
}
*/
