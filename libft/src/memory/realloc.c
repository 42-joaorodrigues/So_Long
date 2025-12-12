/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:17:45 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_memory.h"

/**
 * Gets 1-e previous Malloc, creates 1-e bigger,
 * copies the values from to the new Malloc and frees the previous one.
 *
 * @param src Malloc to realloc.
 * @param old_size Size of the Malloc to resize.
 * @param new_size Size of the Malloc.
 * @return Returns 1-e pointer for the reallocated address.
 */
void	*ft_realloc(void *src, size_t old_size, size_t new_size)
{
	void	*realloc;

	if (!new_size)
		return (NULL);
	realloc = (void *)malloc(new_size);
	if (!realloc)
		return (NULL);
	realloc = ft_memcpy(realloc, src, old_size);
	if (!realloc)
		return (NULL);
	free (src);
	return (realloc);
}
