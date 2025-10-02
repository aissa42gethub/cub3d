/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:28:29 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/25 14:31:10 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copy a block of memory from one location to another - overlap is handled

#include "libft.h"

//if destination and source are the same, return immediately
//copy forward if there's no risk of overlap
//copy backward to handle overlapping regions
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s || len == 0)
		return (dst);
	if (d < s)
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
/*
//cc -Wall -Wextra -Werror ft_memmove.c libft.a -o ft_memmove.out
//./ft_memmove.out
#include <stdio.h>
#include <string.h>
//move "Hello" to start at position 2
int	main(void)
{
	char lib[] = "Hello 42!";
	char ft[] = "Hello 42!";
	
	printf("[lib pre]    '%s'\n", lib);
	memmove(lib + 1, lib, 3);
	printf("[lib post]   '%s'\n\n", lib);
	//[lib pre]    'Hello 42!'
	//[lib post]   'HHelo 42!'
	
	printf("[ft pre]     '%s'\n", ft);
	ft_memmove(ft + 1, ft, 3);
	printf("[ft post]    '%s'\n\n", ft);
	//[ft pre]     'Hello 42!'
	//[ft post]    'HHelo 42!'
	
	return (0);
}
*/
