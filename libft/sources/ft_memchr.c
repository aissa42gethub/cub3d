/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:28:04 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:33:08 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locate the first occurrence of a character in string

#include "libft.h"

//cast parameter to pointer
//iterate until n parameter
//return pointer to the first occurrence
//return NULL if not found
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		target;

	ptr = (const unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == target)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
//cc -Wall -Wextra -Werror ft_memchr.c libft.a -o ft_memchr.out
//./ft_memchr.out
#include <stdio.h>
#include <string.h>
int	main(void) {
	char str[] = "Hello 42!";
	char a = 'o';
	char b = 'x';
	char *lib_a = memchr(str, a, sizeof(str));
	char *ft_a = ft_memchr(str, a, sizeof(str));
	char *lib_b = memchr(str, b, sizeof(str));
	char *ft_b = ft_memchr(str, b, sizeof(str));

	printf("[lib]   target:'%c'   result:'%s'   pos:%ld\n", 
		a, lib_a, lib_a - str);
	printf("[ft]    target:'%c'   result:'%s'   pos:%ld\n\n", 
		a, ft_a, ft_a - str);
	//[lib]   target:'o'   result:'o 42!'   pos:4
	//[ft]    target:'o'   result:'o 42!'   pos:4

	printf("[lib]   target:'%c'   result:'%s'   pos:%ld\n", 
		b, lib_b, lib_b - str);
	printf("[ft]    target:'%c'   result:'%s'   pos:%ld\n\n", 
		b, ft_b, ft_b - str);
	//[lib]   target:'x'   result:'(null)'   pos:-6171866520
	//[ft]    target:'x'   result:'(null)'   pos:-6171866520

	return (0);
}
*/