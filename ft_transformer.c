/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:08:38 by nreher            #+#    #+#             */
/*   Updated: 2023/02/02 16:31:27 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writehex(unsigned long nbr, char c, int checker)
{
	char			*base;
	int				crwl;
	static int		check;

	if (check != 0)
		check = 0;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0 && checker == 0)
	{
		write(1, "0", 2);
		return (1);
	}
	if (nbr > 0)
	{
		crwl = nbr % 16;
		nbr = nbr / 16;
		ft_writehex(nbr, c, 1);
		write(1, &base[crwl], 1);
	}
	check ++;
	return (check - 1);
}

int	ft_putunbr_fd(unsigned int n)
{
	char			o;
	static int		out;

	if (n > 9)
		ft_putunbr_fd(n / 10);
	o = (n % 10) + '0';
	out++;
	write(1, &o, 1);
	return (out);
}

int	ft_putnstr_fd(char *s)
{
	int	c;

	c = 0;
	while (s[c])
	{
		write(1, &s[c], 1);
		c++;
	}
	return (c);
}

int	ft_putnnbr_fd(int n)
{
	char			o;
	static int		c;

	c = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		c++;
	}
	if (n > 9)
		ft_putnnbr_fd(n / 10);
	o = (n % 10) + '0';
	write(1, &o, 1);
	c++;
	return (c);
}
