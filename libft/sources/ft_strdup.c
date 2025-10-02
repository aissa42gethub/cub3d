/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:31 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:30:33 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//allocate memory and duplicates a string

#include "libft.h"

//get string length
//allocate memory and include extra value for null terminator
//check if malloc succeds
//copy the string to pointer
//add null terminator at the end
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}
/*
// cc -Wall -Wextra -Werror ft_strdup.c libft.a -o ft_strdup.out
// ./ft_strdup.out
//check if memory allocation was successful
//if successful, free the allocated memory before exiting
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*str_a = "Hello 42!";
	char		*lib_a;
	char		*ft_a;
	const char	*str_b = "Hi\tTherE @42";
	char		*lib_b;
	char		*ft_b;

	lib_a = strdup(str_a);
	printf("[lib]   str:'%s'   out:'%s'\n", str_a, lib_a);
	free(lib_a);
	//[lib]   str:'Hello 42!'   out:'Hello 42!'

	ft_a = ft_strdup(str_a);
	printf("[ft]    str:'%s'   out:'%s'\n\n", str_a, ft_a);
	free(ft_a);
	//[ft]    str:'Hello 42!'   out:'Hello 42!'

	lib_b = strdup(str_b);
	printf("[lib]   str:'%s'   out:'%s'\n", str_b, lib_b);
	free(lib_b);
	//[lib]   str:'Hi	TherE @42'   out:'Hi	TherE @42'

	ft_b = ft_strdup(str_b);
	printf("[ft]    str:'%s'   out:'%s'\n\n", str_b, ft_b);
	free(ft_b);
	//[ft]    str:'Hi	TherE @42'   out:'Hi	TherE @42'

	return (0);
}
*/