/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_partial_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:06:31 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_memory.h"

/**
 * Frees the matrix lines from the given array to 0.\n
 * Afterward frees matrix pointer itself.
 *
 * @param matrix Matrix to free.
 * @param index Index to start freeing from.
 */
void	ft_free_partial_matrix(void **matrix, int index)
{
	if (!matrix)
		return ;
	while (index >= 0)
		free(matrix[index--]);
	free(matrix);
	matrix = NULL;
}
