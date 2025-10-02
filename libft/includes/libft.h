/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:43:44 by azsaleh           #+#    #+#             */
/*   Updated: 2025/08/31 22:45:25 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>

//FUNCTION PROTOTYPE

//convert a string containing a numerical value into an integer
int		ft_atoi(const char *str);

//set all bytes in a block of memory to zero
void	ft_bzero(void *s, size_t n);

//allocate memory for an array of elements and initialize all bytes to zero
void	*ft_calloc(size_t count, size_t size);

//check if character is alphabet or number
int		ft_isalnum(int c);

//check if character is an alphabet
int		ft_isalpha(int c);

//check if character is an ascii character
int		ft_isascii(int c);

//check if character is a number
int		ft_isdigit(int c);

//check if character is printable, including space
int		ft_isprint(int c);

//converts integer to string
char	*ft_itoa(int n);

//locate the first occurrence of a character in string
void	*ft_memchr(const void *s, int c, size_t n);

//compares two blocks of memory byte by byte
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//copy a block of memory from one location to another - cannot handle overlap
void	*ft_memcpy(void *dst, const void *src, size_t n);

//copy a block of memory from one location to another within a range
void	*ft_memcpy_rng(void *dst, const void *src, size_t start, size_t end);

//copy a block of memory from one location to another - overlap is handled
void	*ft_memmove(void *dst, const void *src, size_t len);

//set a block of memory to a specific value
void	*ft_memset(void *b, int c, size_t len);

//output the character ’c’ to the given file descriptor
void	ft_putchar_fd(char c, int fd);

//output the string ’s’ to the given file descriptor followed by a newline
void	ft_putendl_fd(char *s, int fd);

//output the integer ’n’ to the given file descriptor
void	ft_putnbr_fd(int n, int fd);

//output the string ’s’ to the given file descriptor
void	ft_putstr_fd(char *s, int fd);

//separates a string into an array based on a given character
char	**ft_split(char const *s, char c);

//search for last occurence of character and return string til null-terminator
char	*ft_strchr(const char *s, int c);

//allocate memory and duplicates a string
char	*ft_strdup(const char *s1);

//applies function f to each character in string
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//combine 2 strings
char	*ft_strjoin(char const *s1, char const *s2);

//concatenate two strings w/ null-termination and within buffer size
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

//copies strings w/ buffer overflow prevention and always null-terminated
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//calculate the length of a string (excluding the null terminator '\0')
size_t	ft_strlen(const char *s);

//applies function f to each character in string and allocates to memory
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//compares two strings and return the difference
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//search within length of string and return substring until null-terminator
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

//search for last occurence of character and return string til null-terminator
char	*ft_strrchr(const char *s, int c);

//remove all set of characters that are found within a given string
char	*ft_strtrim(char const *s1, char const *set);

//extract from a string based on a starting character to a determined range
char	*ft_substr(char const *s, unsigned int start, size_t len);

//converts uppercase characters to lowercase
int		ft_tolower(int c);

//converts lowercase characters to uppercase
int		ft_toupper(int c);

//print out to console
int		ft_printf(const char *format, ...);

//get string line from file descriptor. each execution iterates to next line
char	*get_next_line(int fd);

//free old pointer and swap to new pointer. useful w/ ft_strjoin or ft_strtrim
char	*ft_freeswpptr(char *old, char *new);

//convert a numerical string into a long integer
long	ft_atol(const char *str);

//frees all allocated memory from 2d array
void	ft_freearray(char **array);

//convert a string representation of a number in a given base to an integer
int		ft_atoi_base(const char *str, int str_base);

//check if string is hexadecimal
bool	ft_ishex(const char *str);

#endif
