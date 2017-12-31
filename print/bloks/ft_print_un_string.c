/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 23:41:54 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/30 23:41:55 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_un_string_with(t_struct *flags, int *pok, int min_size)
{
	char a[min_size + 1];

	a[min_size + 1] = '\0';
	ft_memset(a, ' ', min_size);
	if (min_size != 0)
	{
		if (flags->minus == '-')
		{
			while (*pok)
				ft_putchar_un(*pok++);
			write(1, a, min_size);
		}
		else
		{
			write(1, a, min_size);
			while (*pok)
				ft_putchar_un(*pok++);
		}
	}
	else
	{
		while (*pok)
			ft_putchar_un(*pok++);
	}
}

void	find_size(t_struct *flags, int *length, wchar_t **value, wchar_t **tmp)
{
	int count2;
	int count;
	wchar_t *res;
	wchar_t *index;

	count2 = 0;
	count = 0;
	if (flags->presizion != -1 && *length > flags->presizion)
	{
		res = *value;
		index = *tmp;
		while (*res)
		{
			if ((count += count_bite(*res)) <= flags->presizion)
			{
				count2 = count;
				*index++ = *res++;
			}
			else
				break ;
		}
		*length = count2;
		*value = *tmp;
	}
}

int 	ft_bitslen(wchar_t *res)
{
	int count;

	count = 0;
	while (*res)
	{
		count += count_bite(*res);
		res++;
	}
	return (count);
}

void	ft_print_unic_string(va_list ap, t_struct *flags)
{
	wchar_t *value;
	wchar_t *tmp;
	int length;
	int min_size;

	value = va_arg(ap, wchar_t*);
	tmp = (wchar_t*)malloc(sizeof(wchar_t) * (flags->presizion + 1));
	length = ft_bitslen(value);
	ft_bzero(tmp, sizeof(wchar_t) * (flags->presizion + 1));
	find_size(flags, &length, &value, &tmp);
	min_size = ft_min_pole_s(flags, length);
	flags->write_count += length + min_size;
	ft_print_un_string_with(flags, value, min_size);
	free(tmp);
	tmp = NULL;
}
