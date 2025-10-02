/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:28:48 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:28:49 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//output the character ’c’ to the given file descriptor

#include "libft.h"

//iterate and write each string character to output
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
//cc -Wall -Wextra -Werror ft_putchar_fd.c libft.a -o ft_putchar_fd.out
//./ft_putchar_fd.out
int	main(void)
{
	ft_putchar_fd('A', 1);
	write(1, "\n\n", 2);
	//A

	ft_putchar_fd('!', 1);
	write(1, "\n\n", 2);
	//!

	return (0);
}
*/