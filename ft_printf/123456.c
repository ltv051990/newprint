
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
	int tmp;

	tmp = ft_search(len = b >= 0 ? b : b * -1);
	src = ft_itoa(b);
	if (b < 0) // прибираємо знак перед числом в string
	{
		tmp1 = ft_strdup(src + 1);
		ft_strdel(&src);
		src = tmp1;
	}
	if (flags->presizion > tmp) // добавляємо нулі перед числом коли точність
	{
		*a = ft_strnew(flags->presizion + 1);
		ft_memset(*a, '0', flags->presizion - tmp);
		*a = ft_strcat(*a, src);
		free(src);
	}
	else 
		*a = src;
}

static		void	ft_nbstr_with_minsize(char **a, long long b, t_struct *flags)
{
	char *g;
	int length = b >= 0 ? ft_strlen(*a) : ft_strlen(*a) + 1;
	int min_size2 = ft_min_pole_s(flags, length);
	if (flags->presizion == -1 && flags->minus != '-' && flags->min_size > length)
	{
		g = ft_strnew(flags->min_size);
		if (b < 0 && (flags->space == 1 || flags->plus == '+'))
		{
			ft_memset(g + 1, '0', min_size2);
			ft_strcat(g + 1 + min_size2, *a);
			ft_strdel(a);
			*a = g; 
		}
		else
		{
			ft_memset(g, '0', min_size2);
			ft_strcat(g + min_size2, *a);
			ft_strdel(a);
			*a = g;
		}
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
	char *c;
	ft_take_b(&b, ap, flags);
	ft_nbstr_with_prezition(&a, b, flags);
	ft_nbstr_with_minsize(&a, b, flags);
	if (b < 0 || (b >= 0 && flags->plus == '+') || (flags->minus == '-' || flags->space == 1))
	{
		if (b < 0)
			c = ft_strjoin("-", a);
		else if (b >= 0 && flags->plus == '+')
			c = ft_strjoin("+", a);
		else if (flags->space == 1 && b >= 0 && flags->plus != '+')
			c = ft_strjoin(" ", a);
		ft_strdel(&a);
		a = c;
	}
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}