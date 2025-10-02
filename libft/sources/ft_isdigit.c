/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:57:38 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 15:59:24 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if character is a number

#include "libft.h"

//if character is a number, return 1
//else return 0
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
//cc -Wall -Wextra -Werror ft_isdigit.c libft.a -o ft_isdigit.out
//./ft_isdigit.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f, g;

	a = '4';
	printf("[lib]   '%c':%d\n", a, isdigit(a));
	printf("[ft]    '%c':%d\n\n", a, ft_isdigit(a));
	//[lib]   '4':1
	//[ft]    '4':1

	b = '0';
	printf("[lib]   '%c':%d\n", b, isdigit(b));
	printf("[ft]    '%c':%d\n\n", b, ft_isdigit(b));
	//[lib]   '0':1
	//[ft]    '0':1

	c = 'y';
	printf("[lib]   '%c':%d\n", c, isdigit(c));
	printf("[ft]    '%c':%d\n\n", c, ft_isdigit(c));
	//[lib]   'y':0
	//[ft]    'y':0

	d = 'H';
	printf("[lib]   '%c':%d\n", d, isdigit(d));
	printf("[ft]    '%c':%d\n\n", d, ft_isdigit(d));
	//[lib]   'H':0
	//[ft]    'H':0

	e = '?';
	printf("[lib]   '%c':%d\n", e, isdigit(e));
	printf("[ft]    '%c':%d\n\n", e, ft_isdigit(e));
	//[lib]   '?':0
	//[ft]    '?':0

	f = '\t';
	printf("[lib]   '%c':%d\n", f, isdigit(f));
	printf("[ft]    '%c':%d\n\n", f, ft_isdigit(f));
	//[lib]   '	':0
	//[ft]    '	':0

	g = ' ';
	printf("[lib]   '%c':%d\n", g, isdigit(g));
	printf("[ft]    '%c':%d\n\n", g, ft_isdigit(g));
	//[lib]   ' ':0
	//[ft]    ' ':0

	return (0);
}
*/