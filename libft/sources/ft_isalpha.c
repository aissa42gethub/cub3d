/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:19:30 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/12 15:59:08 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if character is an alphabet

#include "libft.h"

//if character is between lowercase and uppercase ranges, return 1
//else, return 0
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
//cc -Wall -Wextra -Werror ft_isalpha.c libft.a -o ft_isalpha.out
//./ft_isalpha.out
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	a, b, c, d, e, f;

	a = 'n';
	printf("[lib]   '%c':%d\n", a, isalpha(a));
	printf("[ft]    '%c':%d\n\n", a, ft_isalpha(a));
	//[lib]   'n':1
	//[ft]    'n':1

	b = 'S';
	printf("[lib]   '%c':%d\n", b, isalpha(b));
	printf("[ft]    '%c':%d\n\n", b, ft_isalpha(b));
	//[lib]   'S':1
	//[ft]    'S':1

	c = '4';
	printf("[lib]   '%c':%d\n", c, isalpha(c));
	printf("[ft]    '%c':%d\n\n", c, ft_isalpha(c));
	//[lib]   '4':0
	//[ft]    '4':0

	d = '!';
	printf("[lib]   '%c':%d\n", d, isalpha(d));
	printf("[ft]    '%c':%d\n\n", d, ft_isalpha(d));
	//[lib]   '!':0
	//[ft]    '!':0

	e = '\t';
	printf("[lib]   '%c':%d\n", e, isalpha(e));
	printf("[ft]    '%c':%d\n\n", e, ft_isalpha(e));
	//[lib]   '	':0
	//[ft]    '	':0

	f = ' ';
	printf("[lib]   '%c':%d\n", f, isalpha(f));
	printf("[ft]    '%c':%d\n\n", f, ft_isalpha(f));
	//[lib]   ' ':0
	//[ft]    ' ':0

	return (0);
}
*/