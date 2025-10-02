/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:38:35 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 16:00:21 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//converts lowercase characters to uppercase

#include "libft.h"

//if character is lowercase, subtract 32 to convert to uppercase
//else, return character as is
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
//cc -Wall -Wextra -Werror ft_toupper.c libft.a -o ft_toupper.out
//./ft_toupper.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f;

	a = 'a';
	printf("[lib]   '%c' -> '%c'\n", a, toupper(a));
	printf("[ft]    '%c' -> '%c'\n\n", a, ft_toupper(a));
	//[lib]   'a' -> 'A'
	//[ft]    'a' -> 'A'

	b = 's';
	printf("[lib]   '%c' -> '%c'\n", b, toupper(b));
	printf("[ft]    '%c' -> '%c'\n\n", b, ft_toupper(b));
	//[lib]   's' -> 'S'
	//[ft]    's' -> 'S'

	c = 'M';
	printf("[lib]   '%c' -> '%c'\n", c, toupper(c));
	printf("[ft]    '%c' -> '%c'\n\n", c, ft_toupper(c));
	//[lib]   'M' -> 'M'
	//[ft]    'M' -> 'M'

	d = '$';
	printf("[lib]   '%c' -> '%c'\n", d, toupper(d));
	printf("[ft]    '%c' -> '%c'\n\n", d, ft_toupper(d));
	//[lib]   '$' -> '$'
	//[ft]    '$' -> '$'

	e = ' ';
	printf("[lib]   '%c' -> '%c'\n", e, toupper(e));
	printf("[ft]    '%c' -> '%c'\n\n", e, ft_toupper(e));
	//[lib]   ' ' -> ' '
	//[ft]    ' ' -> ' '

	f = '\t';
	printf("[lib]   '%c' -> '%c'\n", f, toupper(f));
	printf("[ft]    '%c' -> '%c'\n\n", f, ft_toupper(f));
	//[lib]   '	' -> '	'
	//[ft]    '	' -> '	'

	return (0);
}
*/