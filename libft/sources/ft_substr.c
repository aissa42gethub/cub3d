/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:25 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/06 12:50:28 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//extract from a string based on a starting character to a determined range

#include "libft.h"

//null pointer check for s
//get string length of s
//return empty string if start exceeds length to avoid unnecessary malloc
//set finish value by subtracting string length and start. limit if needed
//memory allocate return pointer
//copy substring value to pointer
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	finish;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	finish = s_len - start;
	if (finish > len)
		finish = len;
	ptr = (char *)malloc(sizeof(char) * (finish + 1));
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s + start, finish + 1);
	return (ptr);
}
/*
//cc -Wall -Wextra -Werror ft_substr.c libft.a -o ft_substr.out
//./ft_substr.out
#include <stdio.h>
int	main(void)
{
	char			s[] = "Hello 42!";
	unsigned int	start;
	size_t			len;
	char			*ptr;

	start = 2;
	len = 8;
	ptr = ft_substr(s, start, len);
	printf("s:'%s'   start:%d   len:%zu   ptr:'%s'\n\n", s, start, len, ptr);
	free(ptr);
	//s:'Hello 42!'   start:2   len:8   ptr:'llo 42!'

	start = 7;
	len = 1;
	ptr = ft_substr(s, start, len);
	printf("s:'%s'   start:%d   len:%zu   ptr:'%s'\n\n", s, start, len, ptr);
	free(ptr);
	//s:'Hello 42!'   start:7   len:1   ptr:'2'

	start = 1;
	len = 6;
	ptr = ft_substr(s, start, len);
	printf("s:'%s'   start:%d   len:%zu   ptr:'%s'\n\n", s, start, len, ptr);
	free(ptr);
	//s:'Hello 42!'   start:1   len:6   ptr:'ello 4'

	start = 0;
	len = 3;
	ptr = ft_substr(s, start, len);
	printf("s:'%s'   start:%d   len:%zu   ptr:'%s'\n\n", s, start, len, ptr);
	free(ptr);
	//s:'Hello 42!'   start:0   len:3   ptr:'Hel'

	start = 3;
	len = 0;
	ptr = ft_substr(s, start, len);
	printf("s:'%s'   start:%d   len:%zu   ptr:'%s'\n\n", s, start, len, ptr);
	free(ptr);
	//s:'Hello 42!'   start:3   len:0   ptr:'(null)'

	return (0);
}
*/