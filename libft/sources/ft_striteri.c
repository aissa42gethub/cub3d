/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:41 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:40:37 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//apply function f to each character in string

#include "libft.h"

//check for null pointers
//iterate by looping through each character, calling the function f each time
//apply f function by passing the current index and address of the character
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
//cc -Wall -Wextra -Werror ft_striteri.c libft.a -o ft_striteri.out
//./ft_striteri.out
#include <stdio.h>
//apply modification of characters at even indices only
//convert to uppercase if lowercase alphabet
void to_uppercase_evenonly(unsigned int index, char *c)
{
	if (index % 2 == 0)
    {
		if (*c >= 'a' && *c <= 'z')
			*c -= 32;
	}
}
int main()
{
	char str[] = "Hello 42!";

	ft_striteri(str, to_uppercase_evenonly);
	printf("str:'%s'\n", str);
	//str:"HeLlO 42!"

	return (0);
}
*/