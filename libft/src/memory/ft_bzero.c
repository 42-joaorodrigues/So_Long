/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:58:03 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_memory.h"

/**
 * Fills the first 'n' bytes of the area pointed by 's'
 * with the NULL character.
 *
 * @param s Pointer to memory area
 * @param n Number of bytes to set
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
