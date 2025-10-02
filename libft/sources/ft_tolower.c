/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:38:35 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 16:00:30 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//converts uppercase characters to lowercase

#include "libft.h"

//if character is uppercase, add 32 convert to lowercase
//else, return as is
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
//cc -Wall -Wextra -Werror ft_tolower.c libft.a -o ft_tolower.out
//./ft_tolower.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f;

	a = 'H';
	printf("[lib]   '%c' -> '%c'\n", a, tolower(a));
	printf("[ft]    '%c' -> '%c'\n\n", a, ft_tolower(a));
	//[lib]   'H' -> 'h'
	//[ft]    'H' -> 'h'

	b = 'Z';
	printf("[lib]   '%c' -> '%c'\n", b, tolower(b));
	printf("[ft]    '%c' -> '%c'\n\n", b, ft_tolower(b));
	//[lib]   'Z' -> 'z'
	//[ft]    'Z' -> 'z'

	c = 'y';
	printf("[lib]   '%c' -> '%c'\n", c, tolower(c));
	printf("[ft]    '%c' -> '%c'\n\n", c, ft_tolower(c));
	//[lib]   'y' -> 'y'
	//[ft]    'y' -> 'y'

	d = '@';
	printf("[lib]   '%c' -> '%c'\n", d, tolower(d));
	printf("[ft]    '%c' -> '%c'\n\n", d, ft_tolower(d));
	//[lib]   '@' -> '@'
	//[ft]    '@' -> '@'

	e = ' ';
	printf("[lib]   '%c' -> '%c'\n", e, tolower(e));
	printf("[ft]    '%c' -> '%c'\n\n", e, ft_tolower(e));
	//[lib]   ' ' -> ' '
	//[ft]    ' ' -> ' '

	f = '\t';
	printf("[lib]   '%c' -> '%c'\n", f, tolower(f));
	printf("[ft]    '%c' -> '%c'\n\n", f, ft_tolower(f));
	//[lib]   '	' -> '	'
	//[ft]    '	' -> '	'

	return (0);
}
*/