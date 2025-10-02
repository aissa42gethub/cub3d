/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:07:30 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 17:50:24 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//concatenate two strings w/ null-termination and within buffer size

#include "libft.h"

//calculate the length of dst and src
//if destination is null and its size is 0, return source length
//if theres no space in destination for null-terminator, return required size
//append src to dst, leaving room for null-terminator
//null-terminate the result
//return the total length of the concatenated string
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while ((j < dstsize - dst_len - 1) && (src[j]))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
//cc -Wall -Wextra -Werror -lbsd ft_strlcat.c libft.a -o ft_strlcat.out
//cc -Wall -Wextra -Werror ft_strlcat.c libft.a -o ft_strlcat.out
//./ft_strlcat.out
#include <stdio.h>
// #include <bsd/string.h>
#include <string.h>
int	main()
{
	char		lib_a[20] = "Hello ";
	char		ft_a[20] = "Hello ";
	const char	*src_a = "42!";
	char		lib_b[20] = "hi\t";
	char		ft_b[20] = "hi\t";
	const char	*src_b = "@42";
	char		lib_c[20] = "";
	char		ft_c[20] = "";
	const char	*src_c = "";
	char		lib_d[20] = "Hello ";
	char		ft_d[20] = "Hello ";
	const char	*src_d = "42!";

	printf("[lib]   dst:'%s'   dstsize:%lu   len:%zu\n", lib_a, 
		sizeof(lib_a), strlcat(lib_a, src_a, sizeof(lib_a)));
	printf("[ft]    dst:'%s'   dstsize:%lu   len:%zu\n\n", ft_a, 
		sizeof(ft_a), ft_strlcat(ft_a, src_a, sizeof(ft_a)));
	//[lib]   dst:'Hello 42!'   dstsize:20   len:9
	//[ft]    dst:'Hello 42!'   dstsize:20   len:9
	
	printf("[lib]   dst:'%s'   dstsize:%lu   len:%zu\n", lib_b, 
		sizeof(lib_b), strlcat(lib_b, src_b, sizeof(lib_b)));
	printf("[ft]    dst:'%s'   dstsize:%lu   len:%zu\n\n", ft_b, 
		sizeof(ft_b), ft_strlcat(ft_b, src_b, sizeof(ft_b)));
	//[lib]   dst:'hi	@42'   dstsize:20   len:6
	//[ft]    dst:'hi	@42'   dstsize:20   len:6

	printf("[lib]   dst:'%s'   dstsize:%lu   len:%zu\n", lib_c, 
		sizeof(lib_c), strlcat(lib_c, src_c, sizeof(lib_c)));
	printf("[ft]    dst:'%s'   dstsize:%lu   len:%zu\n\n", ft_c, 
		sizeof(ft_c), ft_strlcat(ft_c, src_c, sizeof(ft_c)));
	//[lib]   dst:''   dstsize:20   len:0
	//[ft]    dst:''   dstsize:20   len:0

	printf("[lib]   dst:'%s'   dstsize:%d   len:%zu\n", lib_d, 
		3, strlcat(lib_d, src_d, 3));
	printf("[ft]    dst:'%s'   dstsize:%d   len:%zu\n\n", ft_d, 
		3, ft_strlcat(ft_d, src_d, 3));
	//[lib]   dst:'Hello '   dstsize:3   len:6
	//[ft]    dst:'Hello '   dstsize:3   len:6
	
	return (0);
}
*/