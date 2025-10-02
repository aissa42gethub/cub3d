/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:38:39 by azsaleh           #+#    #+#             */
/*   Updated: 2025/06/05 19:02:32 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convert a numerical string into a long integer

#include "libft.h"

//iterate past any whitespace characters within string
//set sign based on whether a negative '-' character is in current iteration
//iterate past next negative or positive character
//iterate while character are numbers
//convert digits to integer
//apply sign to number and return value
long	ft_atol(const char *str)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
