/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:48:03 by azsaleh           #+#    #+#             */
/*   Updated: 2025/06/07 02:14:36 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//return the pointer to the last node of linked list
//start by checking list is valid
//loop until last node is reached
//return pointer
t_list	*ft_go_to_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

//append node to the end of list
//find last node
//allocate memory for new node and check allocation
//if last node is null, set the node_new as the head in linked list
//if not, set the node_last "next" value to the node_new
//set the "list->buf" value in node_new
//set the "next" value in node_new to null
void	ft_append_to_list(t_list **list, char *buf)
{
	t_list	*node_new;
	t_list	*node_last;

	node_last = ft_go_to_last_node(*list);
	node_new = malloc(sizeof(t_list));
	if (node_new == NULL)
		return ;
	if (node_last == NULL)
		*list = node_new;
	else
		node_last->next = node_new;
	node_new->buf = buf;
	node_new->next = NULL;
}

//find if '\n' char exist in linked list string buffers
//start by checking list is valid. if not, return 0
//loop through linked list nodes and their list->buf values
//if '\n' character is found, return index where it is found
//else, return 0
int	ft_check_for_linebreak(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

//create nodes and fill their buf_str before the buffer with '\n' is found
//loop through linked list string buffers while '\n' is not present
//allocate memory with buffer size + 1 ('\0' character) and check allocation
//read the file and store to "buf" pointer
//if number of char_read is 0, free the allocated memory and return void
//add '\0' character to end of buf
//append the node
void	ft_create_new_list(t_list **list, int fd)
{
	int		char_read;	
	char	*buf;

	char_read = 0;
	while (ft_check_for_linebreak(*list) == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append_to_list(list, buf);
	}
}

//this functions returns the string before the '\n' character is found
//check special error conditions. if error, return null
//create linked list and get characters from fd. return null if this fails
//return string line
char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		while (list)
		{
			tmp = list->next;
			free(list->buf);
			free(list);
			list = tmp;
		}
		list = NULL;
		return (NULL);
	}
	ft_create_new_list(&list, fd);
	if (list == NULL)
		return (NULL);
	line = ft_create_new_line(list);
	ft_prep_new_list_and_free(&list);
	return (line);
}

/*
//open file to read its contents
//using get_next_line function, read + print each line until end of file
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s\n", line);

	return (0);
}
*/