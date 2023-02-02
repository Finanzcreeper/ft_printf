/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:28:23 by nreher            #+#    #+#             */
/*   Updated: 2023/02/02 16:31:33 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_decide(va_list args, char c, int out);
int		pointer_maker(unsigned long i, char c, int d);
int		ft_writehex(unsigned long nbr, char c, int checker);
int		ft_putunbr_fd(unsigned int n);
int		ft_putnstr_fd(char *s);
int		ft_putnnbr_fd(int n);

#endif
