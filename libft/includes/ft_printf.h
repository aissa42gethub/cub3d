/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:43:44 by azsaleh           #+#    #+#             */
/*   Updated: 2025/05/28 17:59:42 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printdigit(long n);
int	ft_printdigit_unsigned(long n);
int	ft_printhex(unsigned long n);
int	ft_printhex_uppercase(unsigned int n);
int	ft_printptr(unsigned long n);
int	ft_printformat(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif
