/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:05 by azsaleh           #+#    #+#             */
/*   Updated: 2024/11/15 15:30:06 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//separates a string into an array based on a given character

#include "libft.h"

//count the number of words separated by the delimiter c
//iterate through s
//everytime a character that is not c is found ...
//and previous character in string matches the c character, ...
//increase count
static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

//allocates memory and duplicates a substring from start to end
//allocate the required memory for word
//copy word to new pointer
//add null terminator to end of string
static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

//free all allocated memory
static void	free_all(char **split, int i)
{
	while (i >= 0)
		free(split[i--]);
	free(split);
}

//loops through the input string and splits it into words
//iterate until each word is covered
//skip to the beginning of next word
//find word end
//duplicate the word
//handle memory allocation failure if word_dup fails
//move to next word
//satisfy require where array ends with a null pointer
static char	**fill_array(char const *s, char c, char **split, int word_count)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	while (i < word_count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		split[i] = word_dup(s, start, end);
		if (!split[i])
		{
			free_all(split, i - 1);
			return (NULL);
		}
		start = end;
		i++;
	}
	split[i] = NULL;
	return (split);
}

//ignore if string is empty
//count words in string based on character argument
//allocates memory for the array of strings
//call on helper function fill_array()
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (fill_array(s, c, split, word_count));
}
/*
//cc -Wall -Wextra -Werror ft_split.c libft.a -o ft_split.out
//./ft_split.out
#include <stdio.h>
int main()
{
	char	**split = ft_split("Hello,42,!", ',');
	int		i;

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	//Hello
	//42
	//!

	return (0);
}
*/