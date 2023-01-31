/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:37:04 by nreher            #+#    #+#             */
/*   Updated: 2023/01/31 19:41:02 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		c;
	int		out;

	out = 0;
	va_start(args, input);
	c = 0;
	if (!input)
		return (-1);
	while (input[c])
	{
		if (input[c] == '%')
		{
			out = ft_decide(args, input[c + 1], out);
			c += 2;
		}
		else
		{
			write(1, &input[c], 1);
			c++;
			out++;
		}
	}
	return (out);
}

int	ft_decide(va_list args, char c, int out)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		out++;
	}
	else if (c == 's')
		out += ft_putnstr_fd(va_arg(args, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		out = out + 2 + ft_writehex(va_arg(args, unsigned long long), c, 0);
	}
	else if (c == 'd' || c == 'i')
		out += ft_putnnbr_fd(va_arg(args, int));
	else if (c == 'u')
		out += ft_putunbr_fd(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		out += ft_writehex(va_arg(args, int), c, 0);
	else
	{
		write(1, "%", 1);
		out++;
	}
	return (out);
}
