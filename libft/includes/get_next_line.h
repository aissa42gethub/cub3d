/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:26:41 by azsaleh           #+#    #+#             */
/*   Updated: 2025/06/07 02:15:40 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include "libft.h"

typedef struct list
{
	char		*buf;
	struct list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_go_to_last_node(t_list *list);
void	ft_append_to_list(t_list **list, char *buf);
int		ft_check_for_linebreak(t_list *list);
void	ft_create_new_list(t_list **list, int fd);
int		ft_get_line_len(t_list *list);
void	ft_merge_list_buf(t_list *list, char *line);
char	*ft_create_new_line(t_list *list);
void	ft_free_old_list(t_list **list, t_list *node_new, char *buf);
void	ft_prep_new_list_and_free(t_list **list);

#endif
