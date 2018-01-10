/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:01:46 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/25 18:01:47 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

# define S1(p) (p == 's' || p == 'S' || p == 'p' || p == 'd' || p == 'D')

# define S2(o) (o == 'o' || o == 'O' || o == 'u' || o == 'U' || o == 'x')

# define S3(i) (i == 'X' || i == 'c' || i == 'C' || i == 'i' || i == '%')

# define SPEC_PER(x) (S1(x) || S2(x) || S3(x))

# define FLAGS_SIZE(y) (y == 'h' || y == 'l' || y == 'j' || y == 'z')

# define FM1(u) (u == '#' || u == '0' || u ==  '-')

# define FM2(y) (y == '+' || y == ' ' || y == '.')

# define FL_MODIF(a) (FM1(a) || FM2(a))

# define FLAGS(w) (w == '#' || w ==  '-' || w ==  '+' || w == ' ')

# define INFRM(z) (!SPEC_PER(z) && !FL_MODIF(z) && !FLAGS_SIZE(z) && z != '\0')

typedef struct	s_struct
{
	int			min_size;
	int			presizion;
	int			print_size;
	int			sharp;
	int			space;
	char		plus;
	char		minus;
	char		zero;
	char		mod_size;
	int			write_count;
	char		*string;
	int			count_nb;
	int			un_costil;
	char		char_costil;
	int			size;
	char		*src;
}				t_struct;

uint64_t		ft_atoi_long(char *str);
char			*ft_print_hex(int *tmp, int index);
char			*ft_find_hex(char *av);
int				ft_presizion_s(t_struct *flags, int size_argum);
int				ft_min_pole_s(t_struct *flags, int size_argum);
void			ft_print_s(va_list ap, t_struct *flags, int prapor);
void			ft_print_c(char alpha, t_struct *flags);
void			ft_start_read_c(char format, va_list ap, t_struct *flags);
void			ft_print_p(va_list ap, t_struct *flags);
void			ft_print_unicode_char(va_list ap, t_struct *flags);
void			ft_unic_string(va_list ap, t_struct *flags);
int				count_bite(unsigned int nb);
int				ft_cur_max(unsigned int *a, t_struct *flags);
void			ft_putchar_un(unsigned int nb);
void			ft_print_integer(va_list ap, t_struct *flags);
void			ft_print_big_integer(va_list ap, t_struct *flags);
void			ft_undigit(va_list ap, t_struct *flags);
void			ft_un_big_digit(va_list ap, t_struct *flags);
void			ft_print_x(va_list ap, t_struct *flags, char format);
void			ft_print_o(va_list ap, t_struct *flags, char format);
void			ft_take_unsigned_xo(uint64_t *b, va_list ap, t_struct *flags);
void			ft_presizion_memory(t_struct *flags, char **a, uint64_t b);
char			*ft_print_octet(int *tmp, int index);
void			ft_toapper_if_x(char **a, char x);
size_t			ft_search_un(uint64_t nb);
size_t			ft_search_dig(long long int nb);
void			ft_take_ud(uint64_t *b, va_list ap, t_struct *flags);
void			ft_nbstr_with_minsize(char **a, t_struct *flags);
void			ft_defolt_struct(t_struct *flags);
void			ft_print_argument(char format, va_list ap, t_struct *flags);
int				ft_read_nbsize_flags(char *format, t_struct *flags);
void			ft_start_read(char *format, va_list ap, t_struct *flags);
int				ft_read_spec_start(char *format, va_list ap, t_struct *flags);
int				ft_read_spec(char *format, t_struct *flags, int index);
int				ft_wr_fls(char mod, t_struct *flags);
int				ft_printf(const char *format, ...);

#endif
