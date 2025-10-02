/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:07:49 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 15:59:33 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if character is alphabet or number

#include "libft.h"

//if character is an alphabet or number, return 1
//else, return 0
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
//cc -Wall -Wextra -Werror ft_isalnum.c libft.a -o ft_isalnum.out
//./ft_isalnum.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f, g;

	a = 'i';
	printf("[lib]   '%c':%d\n", a, isalnum(a));
	printf("[ft]    '%c':%d\n\n", a, ft_isalnum(a));
	//[lib]   'i':1
	//[ft]    'i':1

	b = 'B';
	printf("[lib]   '%c':%d\n", b, isalnum(b));
	printf("[ft]    '%c':%d\n\n", b, ft_isalnum(b));
	//[lib]   'B':1
	//[ft]    'B':1

	c = '7';
	printf("[lib]   '%c':%d\n", c, isalnum(c));
	printf("[ft]    '%c':%d\n\n", c, ft_isalnum(c));
	//[lib]   '7':1
	//[ft]    '7':1

	d = '0';
	printf("[lib]   '%c':%d\n", d, isalnum(d));
	printf("[ft]    '%c':%d\n\n", d, ft_isalnum(d));
	//[lib]   '0':1
	//[ft]    '0':1

	e = '$';
	printf("[lib]   '%c':%d\n", e, isalnum(e));
	printf("[ft]    '%c':%d\n\n", e, ft_isalnum(e));
	//[lib]   '$':0
	//[ft]    '$':0

	f = '\t';
	printf("[lib]   '%c':%d\n", f, isalnum(f));
	printf("[ft]    '%c':%d\n\n", f, ft_isalnum(f));
	//[lib]   '	':0
	//[ft]    '	':0

	g = ' ';
	printf("[lib]   '%c':%d\n", g, isalnum(g));
	printf("[ft]    '%c':%d\n\n", g, ft_isalnum(g));
	//[lib]   ' ':0
	//[ft]    ' ':0

	return (0);
}
*/