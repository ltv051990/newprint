/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:23:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/04 16:23:15 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static		size_t	ft_search(uint64_t nb)
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
	char *src;
	long long int len;

	flags->count_nb = ft_search(len = b >= 0 ? b : b * -1);
	src = ft_itoa_long(b);
	if (flags->presizion > flags->count_nb)
	{
		*a = ft_strnew(flags->presizion + 1);
		ft_memset(*a, '0', flags->presizion - flags->count_nb);
		*a = ft_strcat(*a, src);
		free(src);
	}
	else
		*a = src;
	if (b == 0 && flags->presizion == 0)
	{
		ft_strdel(&src);
		*a = ft_strnew(0);
	}
}

static		void	ft_nbstr_with_minsize(char **a, t_struct *flags)
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
		if (delta_size > 0 && flags->minus == '-')
		{
			g = ft_strcpy(g, *a);
			ft_memset(g + ft_strlen(*a), ' ', delta_size);
		}
		else if (delta_size > 0 && flags->minus != '-' && flags->zero == '\0')
		{
			ft_memset(g, ' ', delta_size);
			g = ft_strcat(g, *a);
		}
		else if (flags->minus != '-' && flags->zero == '0')
		{
				ft_memset(g, '0', delta_size);
				g = ft_strcat(g, *a);
		}
		ft_strdel(a);
		*a = g;
	}
}

static void	ft_take_b(uint64_t *b, va_list ap, t_struct *flags)
{
	if (flags->mod_size == 'z' || flags->mod_size == 'j' ||\
		flags->mod_size == 'L' || flags->mod_size == 'l')
		*b = va_arg(ap, uint64_t);
	else if (flags->mod_size == 'h')
		*b = (unsigned short int)va_arg(ap, void*);
	else if (flags->mod_size == 'H')
		*b = (unsigned char)va_arg(ap, void*);
	else
		*b = va_arg(ap, uint32_t);
}

void	ft_undigit(va_list ap, t_struct *flags)
{
	char *a;
	uint64_t b; 

	ft_take_b(&b, ap, flags);
	ft_nbstr_with_prezition(&a, b, flags);
	ft_nbstr_with_minsize(&a, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}

void	ft_un_big_digit(va_list ap, t_struct *flags)
{
	char *a;
	uint64_t b; 

	b = va_arg(ap, uint64_t);
	ft_nbstr_with_prezition(&a, b, flags);
	ft_nbstr_with_minsize(&a, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}