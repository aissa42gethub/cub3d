/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:00:24 by azsaleh           #+#    #+#             */
/*   Updated: 2025/08/31 18:01:50 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//search within length of string and return substring until null-terminator

#include "libft.h"

//if needle is an empty string, return haystack
//loop iterator while it is less than len and haystack reaches null terminator
//if iteration of haystack matches the first character of needle, check further
//second loop checks by iteration through both needle and haystack
//if iteration ends on a null terminator of needle, full match has been found
//return null if no match found within len
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && needle[j]
				&& haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
/*
//cc -Wall -Wextra -Werror -lbsd ft_strnstr.c libft.a -o ft_strnstr.out
//cc -Wall -Wextra -Werror ft_strnstr.c libft.a -o ft_strnstr.out
//./ft_strnstr.out
#include <stdio.h>
// #include <bsd/string.h>
#include <string.h>
int main()
{
	const char	*haystack = "Hello 42!";
	const char	*needle = "llo";
	char		*lib_a = strnstr(haystack, needle, 9);
	char		*ft_a = ft_strnstr(haystack, needle, 9);
	char		*lib_b = strnstr(haystack, needle, 2);
	char		*ft_b = ft_strnstr(haystack, needle, 2);

	printf("[lib]   '%s'+'%s':'%s'   range:9\n", haystack, needle, lib_a);
	printf("[ft]    '%s'+'%s':'%s'   range:9\n\n", haystack, needle, ft_a);
 	//[lib]   'Hello 42!'+'llo':'llo 42!'   range:9
	//[ft]    'Hello 42!'+'llo':'llo 42!'   range:9

	printf("[lib]   '%s'+'%s':'%s'   range:2\n", haystack, needle, lib_b);
 	printf("[ft]    '%s'+'%s':'%s'   range:2\n\n", haystack, needle, ft_b);
	//[lib]   'Hello 42!'+'llo':'(null)'   range:2
	//[ft]    'Hello 42!'+'llo':'(null)'   range:2

	return (0);
}
*/