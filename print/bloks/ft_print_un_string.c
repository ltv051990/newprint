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

void	ft_print_unic_string(va_list ap, t_struct *flags)
{
	wchar_t *value;
	wchar_t *res;
	int count = 0;
	int print_size = 0;

	value = va_arg(ap, wchar_t *);
	res = value;
	while(*res)
	{
		count += count_bite(*res);
		res++;
	}
	flags->write_count += count;	
	while (*value)
		ft_putchar_un(*value++);
	printf("presizion -> %d\n", flags->presizion);
	printf("min_size -> %d\n", flags->min_size);
	printf("zero -> %c\n", flags->zero);
	printf("minus -> %c\n", flags->minus);

}