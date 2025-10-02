/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:29:53 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:39:10 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//output the string ’s’ to the given file descriptor

#include "libft.h"

//return if string is null
//iterate and write each string character to output
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
//cc -Wall -Wextra -Werror ft_putstr_fd.c libft.a -o ft_putstr_fd.out
//./ft_putstr_fd.out
int	main(void)
{
	ft_putstr_fd("Hello 42!\n\n", 1);
	//Hello 42!

	ft_putstr_fd("Hi\t@42\n\n", 1);
	//Hello 42!

	return (0);
}
*/