/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_free_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:59:06 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gnl.h"

void	ft_gnl_free_buffer(char *line, const int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
