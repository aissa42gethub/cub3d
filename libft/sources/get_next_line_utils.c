/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:58:53 by azsaleh           #+#    #+#             */
/*   Updated: 2024/12/29 00:40:13 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//count the number of characters in list->buf nodes until end of string or '\n'
//start by checking list is valid
//loop through all linked list nodes and each list->buf char in string
//increase len variable everytime '\n' is not found
//return length
int	ft_get_line_len(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i++] == '\n')
				return (++len);
			len++;
		}
		list = list->next;
	}
	return (len);
}

//assemble the entire string until '\n' from linked list to string pointer
//start by checking list is valid
//loop through all linked list nodes and all list->buf char values
//merge all node list->buf string values to a single string pointer
//add '\n' and '\0' if newline is found then return void
//add '\0' if no newline is found
void	ft_merge_list_buf(t_list *list, char *line)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->buf[j])
		{
			if (list->buf[j] == '\n')
			{
				line[i] = '\n';
				line[++i] = '\0';
				return ;
			}
			line[i++] = list->buf[j++];
		}
		list = list->next;
	}
	line[i] = '\0';
}

//check if list is valid
//count the total number of characters in list->buf nodes until next '\n'
//allocate memory for the entire string until '\n' + '\0' and check allocation
//assemble the entire string until '\n' from linked list to line pointer
//return line
char	*ft_create_new_line(t_list *list)
{
	int		len;
	char	*line;

	if (list == NULL)
		return (NULL);
	len = ft_get_line_len(list);
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_merge_list_buf(list, line);
	return (line);
}

//frees memory of linked list and set list to new node as head
//start by checking list is valid
//set linked list to tmp and free memory used by list
//if there is content in list->buf of node_new, copy node to list
//else free everything (assumes this is the last part of the entire process)
void	ft_free_old_list(t_list **list, t_list *node_new, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	if (node_new->buf[0])
		*list = node_new;
	else
	{
		free(buf);
		free(node_new);
	}
}

//copy remaining chars after '\n' to new_node and free old nodes from memory
//allocate memory for string buffer and new node then check if valid
//get last node of list
//skip iterator "i" past any '\0' and '\n' characters
//copy remaining characters into buffer then add '\0'
//set the node_new list->buf and ->next values
//free the old nodes from memory
void	ft_prep_new_list_and_free(t_list **list)
{
	int		i;
	int		j;
	char	*buf;
	t_list	*node_new;
	t_list	*node_last;

	buf = malloc(BUFFER_SIZE + 1);
	node_new = malloc(sizeof(t_list));
	if (buf == NULL || node_new == NULL)
		return ;
	node_last = ft_go_to_last_node(*list);
	i = 0;
	j = 0;
	while (node_last->buf[i] && node_last->buf[i] != '\n')
		i++;
	while (node_last->buf[i] && node_last->buf[++i])
		buf[j++] = node_last->buf[i];
	buf[j] = '\0';
	node_new->buf = buf;
	node_new->next = NULL;
	ft_free_old_list(list, node_new, buf);
}
