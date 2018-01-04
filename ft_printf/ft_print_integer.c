/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:25:59 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/02 18:27:49 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static		size_t	ft_search(long long int nb)
{
	size_t	count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static		void	ft_nbstr_with_prezition(char **a, long long b, t_struct *flags)
{
	char *tmp1;
	char *src;
	long long int len;

	flags->count_nb = ft_search(len = b >= 0 ? b : b * -1);
	src = ft_itoa(b);
	if (b < 0) // прибираємо знак перед числом в string
	{
		tmp1 = ft_strdup(src + 1);
		ft_strdel(&src);
		src = tmp1;
	}
	if (flags->presizion > flags->count_nb) // добавляємо нулі перед числом коли точність
	{
		*a = ft_strnew(flags->presizion + 1);
		ft_memset(*a, '0', flags->presizion - flags->count_nb);
		*a = ft_strcat(*a, src);
		free(src);
	}
	else
		*a = src;
	if (b < 0 || flags->plus == '+' || (flags->space == 1 && b >= 0 && flags->plus != '+'))
	{
		if (b < 0)
			src = ft_strjoin("-", *a);
		else if (b >= 0 && flags->plus == '+')
			src = ft_strjoin("+", *a);
		else if (flags->space == 1 && b >= 0 && flags->plus != '+')
			src = ft_strjoin(" ", *a);
		free(*a);
		*a = src;
	}
	if (b == 0 && flags->presizion == 0)
	{
		ft_strdel(&src);
		*a = ft_strnew(0);
	}
}

static		void	ft_nbstr_with_minsize(char **a, long long b, t_struct *flags)
{
	char *g;
	int delta_size;

	if (flags->presizion >= 0 && flags->min_size > (int)ft_strlen(*a))
	{
		g = ft_strnew(flags->min_size);
		if (flags->minus == '-')
		{
			g = ft_strcpy(g, *a);
			ft_memset(g + ft_strlen(*a), ' ', flags->min_size - (int)ft_strlen(*a));
		}
		else
		{
			ft_memset(g, ' ', flags->min_size - (int)ft_strlen(*a));
			ft_strcat(g, *a);	
		}
		ft_strdel(a);
		*a = g;
	}
	delta_size = ft_min_pole_s(flags, (int)ft_strlen(*a));
	if (flags->presizion == -1 && delta_size > 0)
	{
		g = ft_strnew(flags->min_size);
		if (delta_size > 0 && flags->minus == '-')//вирівнювання по лівому краю без нулів із шир
		{
			g = ft_strcpy(g, *a);
			ft_memset(g + ft_strlen(*a), ' ', delta_size);
		}
		else if (delta_size > 0 && flags->minus != '-' && flags->zero == '\0')
		{ // вирівнювання по правому краю з врахуванням шир
			ft_memset(g, ' ', delta_size);
			g = ft_strcat(g, *a);
		}
		else if (flags->minus != '-' && flags->zero == '0')
		{
			if (**a == ' ' || **a == '+' || **a == '-')
			{
				g[0] = **a;
				ft_memset(g + 1, '0', delta_size);
				g = ft_strcat(g, (*a)+1);
			}
			else
			{
				ft_memset(g, '0', delta_size);
				g = ft_strcat(g, *a);
			}
		}
		ft_strdel(a);
		*a = g;
	}
}

void	ft_take_b(long long int *b, va_list ap, t_struct *flags)
{
	if (flags->mod_size == 'z' || flags->mod_size == 'j' ||\
		flags->mod_size == 'L' || flags->mod_size == 'l')
		*b = va_arg(ap, long long);
	else if (flags->mod_size == 'h')
		*b = (short int)va_arg(ap, void*);
	else if (flags->mod_size == 'H')
		*b = (char)va_arg(ap, void*);
	else
		*b = va_arg(ap, int);
}

void	ft_print_integer(va_list ap, t_struct *flags)
{
	char *a;
	long long int b; 

	ft_take_b(&b, ap, flags);
	ft_nbstr_with_prezition(&a, b, flags);
	ft_nbstr_with_minsize(&a, b, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}