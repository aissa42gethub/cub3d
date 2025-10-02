/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:06 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 15:59:41 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if character is an ascii character

#include "libft.h"

//if character is within ascii range, return 1
//else, return 0
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
//cc -Wall -Wextra -Werror ft_isascii.c libft.a -o ft_isascii.out
//./ft_isascii.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f, g;
	int		h, i;

	a = 'q';
	printf("[lib]   '%c':%d\n", a, isascii(a));
	printf("[ft]    '%c':%d\n\n", a, ft_isascii(a));
	//[lib]   'q':1
	//[ft]    'q':1

	b = 'U';
	printf("[lib]   '%c':%d\n", b, isascii(b));
	printf("[ft]    '%c':%d\n\n", b, ft_isascii(b));
	//[lib]   'U':1
	//[ft]    'U':1

	c = '8';
	printf("[lib]   '%c':%d\n", c, isascii(c));
	printf("[ft]    '%c':%d\n\n", c, ft_isascii(c));
	//[lib]   '8':1
	//[ft]    '8':1

	d = '0';
	printf("[lib]   '%c':%d\n", d, isascii(d));
	printf("[ft]    '%c':%d\n\n", d, ft_isascii(d));
	//[lib]   '0':1
	//[ft]    '0':1

	e = '-';
	printf("[lib]   '%c':%d\n", e, isascii(e));
	printf("[ft]    '%c':%d\n\n", e, ft_isascii(e));
	//[lib]   '-':1
	//[ft]    '-':1

	f = '\t';
	printf("[lib]   '%c':%d\n", f, isascii(f));
	printf("[ft]    '%c':%d\n\n", f, ft_isascii(f));
	//[lib]   '	':1
	//[ft]    '	':1

	g = ' ';
	printf("[lib]   '%c':%d\n", g, isascii(g));
	printf("[ft]    '%c':%d\n\n", g, ft_isascii(g));
	//[lib]   ' ':1
	//[ft]    ' ':1

	h = 200;
	printf("[lib]   %d:%d\n", h, isascii(h));
	printf("[ft]    %d:%d\n\n", h, ft_isascii(h));
	//[lib]   200:0
	//[ft]    200:0

	i = -42;
	printf("[lib]   %d:%d\n", i, isascii(i));
	printf("[ft]    %d:%d\n\n", i, ft_isascii(i));
	//[lib]   -42:0
	//[ft]    -42:0

	return (0);
}
*/