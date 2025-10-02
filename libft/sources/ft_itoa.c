/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:27:54 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:27:56 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//converts integer to string

#include "libft.h"

//if number has a negative sign, compensate by increasing len by 1
//iterate and count number of characters
static int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

//num is used to handle edge case for min int
//get number of characters in number
//allocate required memory
//handle negative signs
//set nul terminator
//iterate each character in number and set to its ascii counterpart
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[len] = '\0';
	while (len > 0 && (str[len - 1] != '-'))
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
//cc -Wall -Wextra -Werror ft_itoa.c libft.a -o ft_itoa.out
//./ft_itoa.out
#include <stdio.h>
int	main(void)
{
	char	*a = ft_itoa(1234);
	char	*b = ft_itoa(-6789);

	if (a)
	{
		printf("a:'%s'\n", a);
		free(a);
	}
	printf("\n");
	//a:'1234'

	if (b)
	{
		printf("b:'%s'\n", b);
		free(b);
	}
	printf("\n");
	//b:'-6789'
	return (0);
}
*/