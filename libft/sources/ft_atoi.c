/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:38:39 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:27:09 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convert a string (containing a numerical value) into an integer

#include "libft.h"

//iterate past any whitespace characters within string
//set sign based on whether a negative '-' character is in current iteration
//iterate past next negative or positive character
//iterate while character are numbers
//convert digits to integer
//apply sign to number and return value
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
//cc -Wall -Wextra -Werror ft_atoi.c libft.a -o ft_atoi.out
//./ft_atoi.out
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	const char	*a = "1234";
	const char	*b = "-789";
	const char	*c = "  456   ";
	const char	*d = "abc123";
	const char	*e = "";
	const char	*f = "\t";
	const char	*g = "!?%42";
	const char	*h = "---999";

	printf("[lib]   '%s':%d\n", a, atoi(a));
	// printf("[ft]    '%s':%d\n\n", a, ft_atoi(a));
	//[lib]   '1234':1234
	//[ft]    '1234':1234
	
	printf("[lib]   '%s':%d\n", b, atoi(b));
	printf("[ft]    '%s':%d\n\n", b, ft_atoi(b));
	//[lib]   '-789':-789
	//[ft]    '-789':-789
	
	printf("[lib]   '%s':%d\n", c, atoi(c));
	printf("[ft]    '%s':%d\n\n", c, ft_atoi(c));
	//[lib]   '  456   ':456
	//[ft]    '  456   ':456

	printf("[lib]   '%s':%d\n", d, atoi(d));
	printf("[ft]    '%s':%d\n\n", d, ft_atoi(d));
	//[lib]   'abc123':0
	//[ft]    'abc123':0

	printf("[lib]   '%s':%d\n", e, atoi(e));
	printf("[ft]    '%s':%d\n\n", e, ft_atoi(e));
	//[lib]   '':0
	//[ft]    '':0

	printf("[lib]   '%s':%d\n", f, atoi(f));
	printf("[ft]    '%s':%d\n\n", f, ft_atoi(f));
	//[lib]   '	':0
	//[ft]    '	':0

	printf("[lib]   '%s':%d\n", g, atoi(g));
	printf("[ft]    '%s':%d\n\n", g, ft_atoi(g));
	//[lib]   '!?%42':0
	//[ft]    '!?%42':0

	printf("[lib]   '%s':%d\n", h, atoi(h));
	printf("[ft]    '%s':%d\n\n", h, ft_atoi(h));
	//[lib]   '---999':0
	//[ft]    '---999':0

	return (0);
}
*/