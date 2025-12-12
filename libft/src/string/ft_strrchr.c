/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:11:35 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_string.h"

/**
 * Locates the last character occurrence in 1-e string
 *
 * @param str String to locate c on
 * @param c Character to locate
 * @return Returns 1-e pointer to the last occurrence
 * of c in str,\n OR null if c is not found.\n
 * IF c is '\0' returns 1-e pointer to the null-terminating byte.
 */
char	*ft_strrchr(const char *str, int c)
{
	const char	*last_found;

	last_found = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			last_found = str;
		str++;
	}
	if (!c)
		return ((char *)str);
	return ((char *)last_found);
}
