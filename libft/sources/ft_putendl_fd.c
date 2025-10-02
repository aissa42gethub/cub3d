/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:29:03 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:38:01 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//output the string ’s’ to the given file descriptor followed by a newline

#include "libft.h"

//return if string is null
//iterate and write each string character to output
//write newline at the end
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*
//cc -Wall -Wextra -Werror ft_putendl_fd.c libft.a -o ft_putendl_fd.out
//./ft_putendl_fd.out
int main(void)
{
	ft_putendl_fd("Hello 42!", 1);
	write(1, "\n", 1);
	//Hello 42!

	ft_putendl_fd("Hi\t@42", 1);
	write(1, "\n", 1);
	//Hi	@42

	return (0);
}
*/