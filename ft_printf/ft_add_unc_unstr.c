/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_unc_unstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:10:33 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/09 16:10:35 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
*** check MB_CUR_MAX in %C(UNICODE)
*/

int					ft_cur_max(unsigned int *a, t_struct *flags)
{
	if (MB_CUR_MAX == 1 && (*a > 127 && *a < 256))
	{
		write(1, a, 1);
		flags->write_count += 1;
		return (-1);
	}
	if (MB_CUR_MAX == 1 && *a > 255)
	{
		flags->un_costil = -1;
		return (-1);
	}
	return (1);
}
