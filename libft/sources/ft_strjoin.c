/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:11 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/06 12:48:19 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//combine 2 strings

#include "libft.h"

//null check
//get string length of both strings
//allocate the required memory
//copy s1 to new pointer
//copy s2 to new pointer after s1
//add null terminator at the end
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1_size;
	int		s2_size;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < s1_size)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < s1_size + s2_size)
	{
		ptr[i] = s2[i - s1_size];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
//cc -Wall -Wextra -Werror ft_strjoin.c libft.a -o ft_strjoin.out
//./ft_strjoin.out
#include <stdio.h>
int	main(void)
{
	char	s1[] = "Hello ";
	char	s2[] = "42!";
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	printf("s1:'%s'   s2:'%s'   ptr:'%s'\n", s1, s2, ptr);
	free(ptr);
	//s1:'Hello '    s2:'42!'   ptr:'Hello 42!'

	return (0);
}
*/