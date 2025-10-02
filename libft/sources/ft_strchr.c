/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:21:46 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:39:50 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns a pointer to the first occurence of character in string

#include "libft.h"

//increment through each character in string
//during each iteration, check if character matches the character in string
//exit loop if successful
//if iteration reaches end of string, character is not found and return 0
char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
//cc -Wall -Wextra -Werror ft_strchr.c libft.a -o ft_strchr.out
//./ft_strchr.out
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[] = "abcdefghijkl";
	char	b[] = "abcdefABCDEF";
	char	c[] = "ghijklghijkl";
	char	d[] = "\0";

	printf("[lib]   '%s':[e]'%s'\n", a, strchr(a, 'e'));
	printf("[ft]    '%s':[e]'%s'\n\n", a, ft_strchr(a, 'e'));
	//[lib]   'abcdefghijkl':[e]'efghijkl'
	//[ft]    'abcdefghijkl':[e]'efghijkl'

	printf("[lib]   '%s':[j]'%s'\n", a, strchr(a, 'j'));
	printf("[ft]    '%s':[j]'%s'\n\n", a, ft_strchr(a, 'j'));
	//[lib]   'abcdefghijkl':[j]'jkl'
	//[ft]    'abcdefghijkl':[j]'jkl'

	printf("[lib]   '%s':[D]'%s'\n", b, strchr(b, 'D'));
	printf("[ft]    '%s':[D]'%s'\n\n", b, ft_strchr(b, 'D'));
	//[lib]   'abcdefABCDEF':[D]'DEF'
	//[ft]    'abcdefABCDEF':[D]'DEF'

	printf("[lib]   '%s':[e]'%s'\n", b, strchr(b, 'e'));
	printf("[ft]    '%s':[e]'%s'\n\n", b, ft_strchr(b, 'e'));
	//[lib]   'abcdefABCDEF':[e]'efABCDEF'
	//[ft]    'abcdefABCDEF':[e]'efABCDEF'

	printf("[lib]   '%s':[i]'%s'\n", c, strchr(c, 'i'));
	printf("[ft]    '%s':[i]'%s'\n\n", c, ft_strchr(c, 'i'));
	//[lib]   'ghijklghijkl':[i]'ijklghijkl'
	//[ft]    'ghijklghijkl':[i]'ijklghijkl'

	printf("[lib]   '%s':[x]'%s'\n", c, strchr(c, 'x'));
	printf("[ft]    '%s':[x]'%s'\n\n", c, ft_strchr(c, 'x'));
	//[lib]   'ghijklghijkl':[x]'(null)'
	//[ft]    'ghijklghijkl':[x]'(null)'

	printf("[lib]   '%s':[x]'%s'\n", d, strchr(d, 'x'));
	printf("[ft]    '%s':[x]'%s'\n\n", d, ft_strchr(d, 'x'));
	//[lib]   'ghijklghijkl':[x]'(null)'
	//[ft]    'ghijklghijkl':[x]'(null)'

	return (0);
}
*/