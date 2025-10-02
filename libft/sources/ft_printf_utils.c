/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:58:40 by azsaleh           #+#    #+#             */
/*   Updated: 2025/01/06 19:09:35 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//use long as argument to handle negative digits ie -2147483648 -> 2147483648
//if base is -10, we have an unsigned decimal. add 2^32 and use base 10
//decide which symbol set to use. alt set is needed to handle uppercase hex
//write '-' char if number is negative. add 1 to handle recursion and its count
//we modulo base by 17 so we have base 16 from 32
//write symbol
int	ft_printdigit(long n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		count = write(1, "-", 1);
		return (count + ft_printdigit(-n));
	}
	if (n >= 10)
		count = ft_printdigit(n / 10);
	return (count + ft_printchar(symbols[n % 10]));
}

//use long as argument to handle negative digits ie 4294967296
//if base is -10, we have an unsigned decimal. add 2^32 and use base 10
//decide which symbol set to use. alt set is needed to handle uppercase hex
//write '-' char if number is negative. add 1 to handle recursion and its count
//we modulo base by 17 so we have base 16 from 32
//write symbol
int	ft_printdigit_unsigned(long n)
{
	int		count;
	char	*symbols;

	if (n < 0)
		return (ft_printdigit_unsigned(4294967296 + n));
	symbols = "0123456789";
	count = 0;
	if (n >= 10)
		count = ft_printdigit_unsigned(n / 10);
	return (count + ft_printchar(symbols[n % 10]));
}

//use unsigned long as argument to handle pointer address from ft_printptr
//if base is -10, we have an unsigned decimal. add 2^32 and use base 10
//decide which symbol set to use. alt set is needed to handle uppercase hex
//we modulo base by 17 so we have base 16 from 32
//write symbol
int	ft_printhex(unsigned long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count = ft_printhex(n / 16);
	return (count + ft_printchar(symbols[n % 16]));
}

//if base is -10, we have an unsigned decimal. add 2^32 and use base 10
//decide which symbol set to use. alt set is needed to handle uppercase hex
//we modulo base by 17 so we have base 16 from 32
//write symbol
int	ft_printhex_uppercase(unsigned int n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count = ft_printhex_uppercase(n / 16);
	return (count + ft_printchar(symbols[n % 16]));
}

//prints address of pointer to file descriptor
int	ft_printptr(unsigned long n)
{
	int		count;

	if (n == 0)
		return (ft_printstr("(nil)"));
	else
		count = write(1, "0x", 2);
	return (count + ft_printhex(n));
}
