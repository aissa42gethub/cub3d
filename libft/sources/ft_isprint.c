/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:40:47 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 15:59:49 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if character is printable, including space

#include "libft.h"

//if character is within 32 and 126, character is printable. so return 1
//else, return 0
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
//cc -Wall -Wextra -Werror ft_isprint.c libft.a -o ft_isprint.out
//./ft_isprint.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f, g, h, i;

	a = 'p';
	printf("[lib]   '%c':%d\n", a, isprint(a));
	printf("[ft]    '%c':%d\n\n", a, ft_isprint(a));
	//[lib]   'p':1
	//[ft]    'p':1

	b = 'N';
	printf("[lib]   '%c':%d\n", b, isprint(b));
	printf("[ft]    '%c':%d\n\n", b, ft_isprint(b));
	//[lib]   'N':1
	//[ft]    'N':1

	c = '2';
	printf("[lib]   '%c':%d\n", c, isprint(c));
	printf("[ft]    '%c':%d\n\n", c, ft_isprint(c));
	//[lib]   '2':1
	//[ft]    '2':1

	d = '0';
	printf("[lib]   '%c':%d\n", d, isprint(d));
	printf("[ft]    '%c':%d\n\n", d, ft_isprint(d));
	//[lib]   '0':1
	//[ft]    '0':1

	e = '@';
	printf("[lib]   '%c':%d\n", e, isprint(e));
	printf("[ft]    '%c':%d\n\n", e, ft_isprint(e));
	//[lib]   '@':1
	//[ft]    '@':1

	f = '\t';
	printf("[lib]   '%c':%d\n", f, isprint(f));
	printf("[ft]    '%c':%d\n\n", f, ft_isprint(f));
	//[lib]   '	':0
	//[ft]    '	':0

	g = ' ';
	printf("[lib]   '%c':%d\n", g, isprint(g));
	printf("[ft]    '%c':%d\n\n", g, ft_isprint(g));
	//[lib]   ' ':1
	//[ft]    ' ':1

	h = 27;
	printf("[lib]   'esc':%d\n", isprint(h));
	printf("[ft]    'esc':%d\n\n", ft_isprint(h));
	//[lib]   'esc':0
	//[ft]    'esc':0

	i = 127;
	printf("[lib]   'del':%d\n", isprint(i));
	printf("[ft]    'del':%d\n\n", ft_isprint(i));
	//[lib]   'del':0
	//[ft]    'del':0

	return (0);
}
*/