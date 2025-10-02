/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:44:27 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 16:04:02 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//calculate the length of a string (excluding the null terminator '\0')

#include "libft.h"

//loop increments length until null character in string is reached
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
//cc -Wall -Wextra -Werror ft_strlen.c libft.a -o ft_strlen.out
//./ft_strlen.out
#include <stdio.h>
#include <string.h>
int	main(void) {
	const char	*a = "Hello 42!";
	const char	*b = "0\t1";
	const char	*c = "";

	printf("[lib]   '%s':%zu\n", a, strlen(a));
	printf("[ft]    '%s':%zu\n\n", a, ft_strlen(a));
	//[lib]   'Hello 42!':9
	//[ft]    'Hello 42!':9

	printf("[lib]   '%s':%zu\n", b, strlen(b));
	printf("[ft]    '%s':%zu\n\n", b, ft_strlen(b));
	//[lib]   '0	1':3
	//[ft]    '0	1':3

	printf("[lib]   '%s':%zu\n", c, strlen(c));
	printf("[ft]    '%s':%zu\n\n", c, ft_strlen(c));
	//[lib]   '':0
	//[ft]    '':0

	return (0);
}
*/