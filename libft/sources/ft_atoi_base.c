/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:38:39 by azsaleh           #+#    #+#             */
/*   Updated: 2025/06/06 17:11:44 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convert a string representation of a number in a given base to an integer

#include "libft.h"

int	is_valid(int ch, int baselen)
{
	int	i;

	i = 0;
	while (i < baselen)
	{
		if (ch == "0123456789abcdef"[i] || ch == "0123456789ABCDEF"[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_space(int c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int	ft_helper(const char *str, int str_base, int sign, int i)
{
	int	res;

	res = 0;
	while (str[i] && is_valid(str[i], str_base))
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sign);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	i;

	if (!str || str_base < 2 || str_base > 16)
		return (0);
	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str_base == 16 && str[i] == '0'
		&& (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	return (ft_helper(str, str_base, sign, i));
}
