/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:59:21 by nreher            #+#    #+#             */
/*   Updated: 2023/02/03 19:26:30 by nreher           ###   ########.fr       */
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
	printf("testing mine:\n");
	a = ft_printf("char		't'		:	'%c'\nstring		'test'		:	'%s'\npointer of char	't'		:	'%p'\nnullpointer:	(nil)		:	'%p'\nint		'1234567'	:	'%d'\nint		'1234567'	:	'%i'\nunsigned int	'4294967295'	:	'%u'\nhex of		'380358127'	:	'%x'\nuppercase hex of'380358127'	:	'%X'\n'%%'\n", c, s, &c, (void *)0, d, d, u, x, x);
	printf("testing original:\n");
		b = printf("char		't'		:	'%c'\nstring		'test'		:	'%s'\npointer of char	't'		:	'%p'\nnullpointer:	(nil)		:	'%p'\nint		'1234567'	:	'%d'\nint		'1234567'	:	'%i'\nunsigned int	'4294967295'	:	'%u'\nhex of		'380358127'	:	'%x'\nuppercase hex of'380358127'	:	'%X'\n'%%'\n", c, s, &c, (void *)0, d, d, u, x, x);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	a = ft_printf("consecutive hex (0,0): %x%x\n",0,0);
	b = printf("consecutive hex (0,0): %x%x\n",0,0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	ft_printf("invalid inputs:\n");
	a = ft_printf(0);
	b = printf(0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	a = ft_printf("nullpointer: %p\n", (void *)0);
	b = printf("nullpointer: %p\n", (void *)0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("pointer -1: %p\n", (void *)-1);
	b = printf("pointer -1: %p\n", (void *)-1);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("hex of -1: %x\n", -1);
	b = printf("hex of -1: %x\n", -1);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("wrong arg: %M %P\n");
	b = printf("wrong arg: %M %P\n");
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("%d\n", -111);
	b = printf("%d\n", -111);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("NULL %s NULL\n", NULL);
	b = printf("NULL %s NULL\n", NULL);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	b = printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	b = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);
	a = ft_printf("{ %x }\n", 0);
	b = printf("{ %x }\n", 0);
	printf("mine: %d=%d :original\n-----------------------------------------\n", a, b);

	return(0);
}
