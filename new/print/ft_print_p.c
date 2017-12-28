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

#include "ft_printf.h"

static unsigned long long int		ft_atoi_long(char *str)
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

static char *ft_print_hex(int *tmp, int index)
{
	char *d = (char *)malloc(sizeof(char) * 20);
	int a;

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
	d[a] = '\0';
	return (d);
}

char *ft_find_hex(char *av)
{
	unsigned long long int a;
	int index;
	int tmp[20];

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

void	ft_print_p(va_list ap, t_struct *flags)
{
	unsigned long a;
	char *k;
	char *b;
	int min_size;

	a = va_arg(ap, unsigned long);
	k = ft_itoa(a);
	b = ft_find_hex(k);
	ft_strdel(&k);
	min_size = ft_min_pole_s(flags, ft_strlen(b) + 2);
	if (min_size != 0)
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
			while(min_size--)
				write(1, " " , 1);
			write(1, "0x", 2);
			write(1, b, ft_strlen(b));
		}
	}
	else
	{
		write(1, "0x", 2);
		write(1, b, ft_strlen(b));
	}
	flags->write_count += 2 + ft_strlen(b) + ft_min_pole_s(flags, ft_strlen(b) + 2);
	ft_strdel(&b);
}
