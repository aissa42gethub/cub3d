/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:34:20 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:48:36 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//remove all character set that are found at the beginning and end of string

#include "libft.h"

//check if character is in string set
static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

//return null if string and set are null
//set start by iterating until character is last found at the top of string
//iterate end until null terminator
//set end by iterating until character is first found at the end of string
//allocate the required memory
//copy the string to new pointer
//add null terminator at the end
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
//cc -Wall -Wextra -Werror ft_strtrim.c libft.a -o ft_strtrim.out
//./ft_strtrim.out
#include <stdio.h>
int	main(void)
{
	char const	str[] = "   Hello 42!   ";
	char const	set[] = " ";
	char		*ptr;

	ptr = ft_strtrim(str, set);
	printf("str:'%s'   set:'%s'   ptr:'%s'\n\n", str, set, ptr);
	free(ptr);
	//str:'   Hello 42!   '   set:' '   ptr:'Hello 42!'

	return (0);
}
*/