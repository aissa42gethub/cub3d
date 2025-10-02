/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:58:40 by azsaleh           #+#    #+#             */
/*   Updated: 2025/05/21 12:32:51 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//prints a single character to file descriptor
//we have a special case UTF-8 encoding of U+FFFD
int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

//prints an entire string to file descriptor
int	ft_printstr(char *s)
{
	int	count;

	if (s == NULL)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

//routes the processing based on print format
int	ft_printformat(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_printchar(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if ((specifier == 'd') || (specifier == 'i'))
		return (ft_printdigit((long)va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_printdigit_unsigned((long)va_arg(ap, int)));
	else if (specifier == 'x')
		return (ft_printhex(va_arg(ap, unsigned int)));
	else if (specifier == 'X')
		return (ft_printhex_uppercase(va_arg(ap, unsigned int)));
	else if (specifier == 'p')
		return (ft_printptr(va_arg(ap, unsigned long)));
	else
		return (write(1, "%", 1));
}

//iterate through variadic arguments
//if char is %, run ft_printformat to handle special cases + ...
//also run va_arg to increment next argument pointer
//if not, write out char
//return number of characters written
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_printformat(*format, ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
