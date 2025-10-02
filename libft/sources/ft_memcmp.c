/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:28:12 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:34:13 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares two blocks of memory byte by byte

#include "libft.h"

//iterate through argument length
//if pointer values do not match, return the difference between them
//if no difference found, return 0
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*byte1;
	const unsigned char	*byte2;

	byte1 = (const unsigned char *)s1;
	byte2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (byte1[i] != byte2[i])
			return (byte1[i] - byte2[i]);
		i++;
	}
	return (0);
}
/*
//cc -Wall -Wextra -Werror ft_memcmp.c libft.a -o ft_memcmp.out
//./ft_memcmp.out
#include <stdio.h>
#include <string.h>
int main()
{
	char	buffer1[] = {1, 2, 3, 4, 5};
	char	buffer2[] = {1, 2, 3, 9, 5};
	int		lib_a = memcmp(buffer1, buffer2, sizeof(buffer1));
	int		ft_a = ft_memcmp(buffer1, buffer2, sizeof(buffer1));
	int		lib_b = memcmp(buffer2, buffer1, sizeof(buffer1));
	int		ft_b = ft_memcmp(buffer2, buffer1, sizeof(buffer1));
	int		lib_c = memcmp(buffer1, buffer1, sizeof(buffer1));
	int		ft_c = ft_memcmp(buffer1, buffer1, sizeof(buffer1));
	
	printf("[lib]   a:%d\n", lib_a);
	printf("[ft]    a:%d\n\n", ft_a);
	//[lib]   a:-5
	//[ft]    a:-5

	printf("[lib]   b:%d\n", lib_b);
	printf("[ft]    b:%d\n\n", ft_b);
	//[lib]   b:5
	//[ft]    b:5

	printf("[lib]   c:%d\n", lib_c);
	printf("[ft]    c:%d\n\n", ft_c);
	//[lib]   c:0
	//[ft]    c:0
	
	return (0);
}
*/