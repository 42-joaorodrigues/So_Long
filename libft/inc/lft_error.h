/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:37:17 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 09:31:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_ERROR_H
# define LFT_ERROR_H

# define ERROR_PINK "\033[38;5;211m"
# define ERROR_RESET "\033[0m"

# define E_NOMEM 69
# define E_FD_OPEN 70

int	*ft_exit_code(void);
int	ft_error(const char *err_str, int err_no);

#endif // JAL_ERROR_H
