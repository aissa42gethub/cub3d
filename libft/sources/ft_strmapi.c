/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:52 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:41:36 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//applies function f to each character in string and allocates to memory

#include "libft.h"

//checked for valid arguments
//calculate the length of the string
//allocate memory for the new string (+1 for the null terminator)
//return null if malloc fails
//apply the function f to each character of the string
//null-terminate the string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*
//cc -Wall -Wextra -Werror ft_strmapi.c libft.a -o ft_strmapi.out
//./ft_strmapi.out
#include <stdio.h>
//shift character by its index
char ft_shift(unsigned int i, char c)
{
	return (c + i);
}
int main()
{
	char    *str;

	str = ft_strmapi("Hello 42!", ft_shift);
	if (str)
	{
		printf("str:Hello 42!   ret:'%s'\n", str);
		free(str);
	}
	//str:Hello 42!   ret:'Hfnos%:9)';

	return (0);
}
*/