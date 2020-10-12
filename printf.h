/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:42:06 by utoomey           #+#    #+#             */
/*   Updated: 2020/07/15 18:58:12 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct		s_flags
{
	int				plus;
	int				minus;
	int				space;
	int				lattice;
	int				zero;
}					t_flags;

typedef struct		s_printf
{
	t_flags			flags;
	int				widht;
	int				accuracy;
	int				percent;
	int				widht_true;
	int				accuracy_true;
}					t_printf;

int					ft_printf(const char *str, ...);
t_printf			parse_modifier(char *str, char end, va_list ap);
int					handler_char(t_printf mdfr, char res);
int					handler_i_u_x_p(t_printf mdfr, char *res, int p_true);
int					handler_string(t_printf mdfr, char *str);
char				*handler(t_printf mdfr, int size, char *res);
char				*unsigned_to_string(unsigned n);
char				*int_to_string(int n);
char				*dec_to_hex_string(unsigned number, int type);
char				*long_dec_to_hex_string(long unsigned number);

#endif
