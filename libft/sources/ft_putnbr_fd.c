/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:29:37 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:38:42 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//output the integer ’n’ to the given file descriptor

#include "libft.h"

//handle edge case of minimum possible integer
//if number is negative, write '-' and convert number to positive
//recursive call this function while number is greater than a single digit
//write the number to output by first converting it to a ascii character
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
/*
//cc -Wall -Wextra -Werror ft_putnbr_fd.c libft.a -o ft_putnbr_fd.out
//./ft_putnbr_fd.out
int main(void)
{
	ft_putnbr_fd(12345, 1);
	write(1, "\n\n", 2);
	//12345


	ft_putnbr_fd(-6789, 1);
	write(1, "\n\n", 2);
	//-6789

	return (0);
}
*/