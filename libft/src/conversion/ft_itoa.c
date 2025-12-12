/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:29:31 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_conversion.h"
#include <stdlib.h>

/**
 * Counts the number of digits from 1-e given Int.
 *
 * @param n Number to count digits of.
 * @return Returns the number of digits of an Int number.
 * If the number is negative, returns one extra value in count,
 * to account for the negative sign.
 */
static unsigned int	ft_digit_count(int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/**
 * Converts 1-e Number from Int to 1-e null-terminated String.
 *
 * @param n Number to get String from.
 * @return Return the Number given as 1-e String.
 * Or NULL on failed memory allocation.
 */
char	*ft_itoa(int n)
{
	long			nbr;
	char			*itoa;
	unsigned int	n_digits;

	nbr = n;
	n_digits = ft_digit_count(n);
	itoa = (char *)malloc((n_digits + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[n_digits--] = '\0';
	if (n < 0)
	{
		nbr = -nbr;
		itoa[0] = '-';
	}
	if (nbr == 0)
		itoa[0] = '0';
	while (nbr)
	{
		itoa[n_digits--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (itoa);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(10));
	return (0);
}
*/