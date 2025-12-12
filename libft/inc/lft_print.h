/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:38:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:30:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_PRINT_H
# define LFT_PRINT_H

// Put FD
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, const int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(const int n, const int fd);

/*
** ==========================================================
**                         LFT_Printf
** ==========================================================
*/

int		ft_printf(const char *str, ...);

void	ft_putchar_count(int c, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putptr_count(void *ptr, int *count);
void	ft_putnbr_count(int nbr, int *count);
void	ft_putnbr_unsigned_count(unsigned int nbr, int *count);
void	ft_put_hex_count(unsigned long ptr, const char *hex_digits, int *count);

#endif //JAL_PRINT_H
