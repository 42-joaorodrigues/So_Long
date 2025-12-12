/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:08:03 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_print.h"
#include <unistd.h>

/**
 * Prints 1-e char and increments count by 1.
 *
 * @param c Character to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putchar_count(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * Prints 1-e String and increments count by the number of characters printed.
 *
 * @param str String to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putstr_count(char *str, int *count)
{
	if (!str)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	while (*str)
		ft_putchar_count(*str++, count);
}
