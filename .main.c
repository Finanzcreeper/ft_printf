/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:59:21 by nreher            #+#    #+#             */
/*   Updated: 2023/02/02 17:22:35 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<limits.h>

int	ft_printf(const char *input, ...);

int main(void)
{
	char			c;
	char			*s;
	int				d;
	unsigned int	x;
	unsigned int	u;
	int				a;
	int				b;

	s = "test";
	c = 't';
	d = 1234567;
	u = 4294967295;
	x = 380358127;
	a = ft_printf("testing:\nchar		't'		:	'%c'\nstring		'test'		:	'%s'\npointer of char	't'		:	'%p'\nnullpointer:	(nil)		:	'%p'\nint		'1234567'	:	'%d'\nint		'1234567'	:	'%i'\nunsigned int	'4294967295'	:	'%u'\nhex of		'380358127'	:	'%x'\nuppercase hex of'380358127'	:	'%X'\n'%%'\n", c, s, &c, (void *)0, d, d, u, x, x);
		b = printf("testing:\nchar		't'		:	'%c'\nstring		'test'		:	'%s'\npointer of char	't'		:	'%p'\nnullpointer:	(nil)		:	'%p'\nint		'1234567'	:	'%d'\nint		'1234567'	:	'%i'\nunsigned int	'4294967295'	:	'%u'\nhex of		'380358127'	:	'%x'\nuppercase hex of'380358127'	:	'%X'\n'%%'\n", c, s, &c, (void *)0, d, d, u, x, x);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	a = ft_printf("%x%x\n",0,0);
	b = printf("%x%x\n",0,0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	a = ft_printf(0);
	b = printf(0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	a = ft_printf("%p\n", (void *)0);
	b = printf("%p\n", (void *)0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	return(0);
}
