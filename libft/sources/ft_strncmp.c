/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:06:49 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 17:06:41 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares two strings and return the difference

#include "libft.h"

//return 0 if n is 0
//iterate until n completes and size
//at each iteration, compare character between both strings
//if different, return difference
//if both strings are exact matches, return 0 
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
//cc -Wall -Wextra -Werror ft_strncmp.c libft.a -o ft_strncmp.out
//./ft_strncmp.out
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char a[] = "Hello 42!";
	char b[] = "Hello 42!";
	char c[] = "Hello42!";

	printf("[lib]   '%s'+'%s':%d (range:9)\n", a, b, strncmp(a, b, 9));
	printf("[ft]    '%s'+'%s':%d (range:9)\n\n", a, b, ft_strncmp(a, b, 9));
	//[lib]   'Hello 42!'+'Hello 42!':0 (range:9)
	//[ft]    'Hello 42!'+'Hello 42!':0 (range:9)

	printf("[lib]   '%s'+'%s':%d (range:9)\n", a, c, strncmp(a, c, 9));
	printf("[ft]    '%s'+'%s':%d (range:9)\n\n", a, c, ft_strncmp(a, c, 9));
	//[lib]   'Hello 42!'+'Hello42!':-20 (range:9)
	//[ft]    'Hello 42!'+'Hello42!':-20 (range:9)

	printf("[lib]   '%s'+'%s':%d (range:2)\n", a, c, strncmp(a, c, 2));
	printf("[ft]    '%s'+'%s':%d (range:2)\n\n", a, c, ft_strncmp(a, c, 2));
	//[lib]   'Hello 42!'+'Hello42!':0 (range:2)
	//[ft]    'Hello 42!'+'Hello42!':0 (range:2)

	return (0);
}
*/