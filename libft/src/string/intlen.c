/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:18:16 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lft_string.h"

size_t	ft_intlen(int i)
{
	size_t	len;

	if (i == 0)
		return (1);
	if (i == INT_MIN)
		return (11);
	len = 0;
	if (i < 0)
	{
		len++;
		i = -i;
	}
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}
