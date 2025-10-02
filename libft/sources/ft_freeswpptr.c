/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeswpptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:38:39 by azsaleh           #+#    #+#             */
/*   Updated: 2025/06/05 18:57:54 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//free old pointer and swap to new pointer. useful w/ ft_strjoin or ft_strtrim

#include "libft.h"

char	*ft_freeswpptr(char *old, char *new)
{
	free(old);
	return (new);
}
