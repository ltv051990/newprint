/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:36:36 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/28 15:36:37 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

uint64_t	ft_atoi_long(char *str)
{
	unsigned long long int res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res);
}

/*
*** write to string in 16 base
*/

char					*ft_print_hex(int *tmp, int index)
{
	char	*d;
	int		a;

	d = ft_strnew(20);
	a = 0;
	while (index >= 0)
	{
		if (tmp[index] >= 0 && tmp[index] <= 9)
			d[a] = '9' - (9 - tmp[index]);
		if (tmp[index] >= 10 && tmp[index] <= 15)
			d[a] = 'f' - (15 - tmp[index]);
		index--;
		a++;
	}
	return (d);
}

/*
*** write to int tab mod/16 base
*/

char							*ft_find_hex(char *av)
{
	unsigned long long int	a;
	int						index;
	int						tmp[20];

	a = ft_atoi_long(av);
	if (a == 0)
		tmp[0] = 0;
	index = 0;
	while (a > 0)
	{
		tmp[index] = a % 16;
		a = a / 16;
		index++;
	}
	return (ft_print_hex(tmp, index - 1));
}

/*
*** write write res when size 0
*/

void							ft_print_p_with_size(t_struct *flags, \
								char *b, int min_size)
{
	if (flags->minus == '-')
	{
		write(1, "0x", 2);
		write(1, b, ft_strlen(b));
		while (min_size--)
			write(1, " ", 1);
	}
	else
	{
		while (min_size--)
			write(1, " ", 1);
		write(1, "0x", 2);
		write(1, b, ft_strlen(b));
	}
}

/*
*** find print size malloc char * and free and write res when size 0
*/

void	ft_presizion_memory(t_struct *flags, char **a, uint64_t b)
{
	char *src;

	src = NULL;
	flags->count_nb = ft_strlen(*a);
	if (flags->presizion > flags->count_nb)
	{
		src = ft_strnew(flags->presizion);
		ft_memset(src, '0', flags->presizion - flags->count_nb);
		src = ft_strcat(src, *a);
		ft_strdel(a);
		*a = src;
	}
	if (b == 0 && flags->presizion == 0)
	{
		ft_strdel(&src);
		*a = ft_strnew(0);
	}
}

void							ft_print_p(va_list ap, t_struct *flags)
{
	unsigned long	a;
	char			*k;
	char			*b;
	int				min_size;

	a = va_arg(ap, unsigned long);
	k = ft_itoa(a);
	if (k[0] == '0' && ft_strlen(k) == 1)
		b = k;
	else
	{
		b = ft_find_hex(k);
		ft_strdel(&k);
	}
	if (flags->presizion != -1)
	ft_presizion_memory(flags, &b, a);
	min_size = ft_min_pole_s(flags, ft_strlen(b) + 2);
	if (min_size != 0)
		ft_print_p_with_size(flags, b, min_size);
	else
	{
		write(1, "0x", 2);
		write(1, b, ft_strlen(b));
	}
	flags->write_count += 2 + ft_strlen(b) + min_size;
	ft_strdel(&b);
}
