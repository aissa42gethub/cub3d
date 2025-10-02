/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:28 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 17:57:46 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copies strings (w/ buffer overflow prevention and always null-terminated)

#include "libft.h"

//calculate the length of the src string
//set destination length to determine number of iterations
//if there is space in the destination buffer, copy the iterated character
//null-terminate the destination string at the end
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		if (src_len >= dstsize)
			dst_len = dstsize - 1;
		else
			dst_len = src_len;
		i = 0;
		while (i < dst_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
//cc -Wall -Wextra -Werror -lbsd ft_strlcpy.c libft.a -o ft_strlcpy.out
//cc -Wall -Wextra -Werror ft_strlcpy.c libft.a -o ft_strlcpy.out
//./ft_strlcpy.out
#include <stdio.h>
// #include <bsd/string.h>
#include <string.h>
int	main(void)
{
	char	src[] = "Hello 42!";
	char	dst[6];

	printf("[lib]   src:'%s'   dst:'%s'   len:%lu   ret:%zu\n", src, dst, 
		sizeof(dst), strlcpy(dst, src, sizeof(dst)));
	printf("[ft]    src:'%s'   dst:'%s'   len:%lu   ret:%zu\n", src, dst, 
		sizeof(dst), ft_strlcpy(dst, src, sizeof(dst)));
	//[lib]   src:'Hello 42!'   dst:'Hello'   len:6   ret:9
	//[ft]    src:'Hello 42!'   dst:'Hello'   len:6   ret:9

	return (0);
}
*/