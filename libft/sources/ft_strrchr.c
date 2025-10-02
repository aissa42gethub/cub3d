/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:21:46 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 16:39:01 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//search for last occurence of character and return string til null-terminator

#include "libft.h"

//iterate through string until null-terminator is reached
//iterate now in reverse
//if character matches with character in string, return pointer
//if iteration completes and no character found, return null
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
//cc -Wall -Wextra -Werror ft_strrchr.c libft.a -o ft_strrchr.out
//./ft_strrchr.out
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[] = "abcdeffedcba";
	char	b[] = "abcdefABCDEF";
	char	c[] = "ghijklghijkl";

	printf("[lib]   '%s':[e]'%s'\n", a, strrchr(a, 'e'));
	printf("[ft]    '%s':[e]'%s'\n\n", a, ft_strrchr(a, 'e'));
	//[lib]   'abcdeffedcba':[e]'edcba'
	//[ft]    'abcdeffedcba':[e]'edcba'

	printf("[lib]   '%s':[E]'%s'\n", a, strrchr(a, 'E'));
	printf("[ft]    '%s':[E]'%s'\n\n", a, ft_strrchr(a, 'E'));
	//[lib]   'abcdeffedcba':[E]'(null)'
	//[ft]    'abcdeffedcba':[E]'(null)'

	printf("[lib]   '%s':[D]'%s'\n", b, strrchr(b, 'D'));
	printf("[ft]    '%s':[D]'%s'\n\n", b, ft_strrchr(b, 'D'));
	//[lib]   'abcdefABCDEF':[D]'DEF'
	//[ft]    'abcdefABCDEF':[D]'DEF'

	printf("[lib]   '%s':[f]'%s'\n", b, strrchr(b, 'f'));
	printf("[ft]    '%s':[f]'%s'\n\n", b, ft_strrchr(b, 'f'));
	//[lib]   'abcdefABCDEF':[f]'fABCDEF'
	//[ft]    'abcdefABCDEF':[f]'fABCDEF'

	printf("[lib]   '%s':[i]'%s'\n", c, strrchr(c, 'i'));
	printf("[ft]    '%s':[i]'%s'\n\n", c, ft_strrchr(c, 'i'));
	//[lib]   'ghijklghijkl':[i]'ijkl'
	//[ft]    'ghijklghijkl':[i]'ijkl'

	printf("[lib]   '%s':[x]'%s'\n", c, strrchr(c, 'x'));
	printf("[ft]    '%s':[x]'%s'\n\n", c, ft_strrchr(c, 'x'));
	//[lib]   'ghijklghijkl':[x]'(null)'
	//[ft]    'ghijklghijkl':[x]'(null)'

	return (0);
}
*/