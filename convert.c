/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:05:49 by utoomey           #+#    #+#             */
/*   Updated: 2020/07/16 14:18:35 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*int_to_string(int n)
{
	char	*res;
	long	number;
	long	copy;
	int		i;

	number = (long)n;
	copy = number;
	i = copy < 0 ? 2 : 1;
	while ((copy /= 10))
		i++;
	res = ft_calloc(i-- + 1, sizeof(char));
	if (n < 0)
	{
		*res = '-';
		number *= -1;
	}
	while (number >= 10)
	{
		res[i--] = '0' + number % 10;
		number /= 10;
	}
	res[i] = '0' + number % 10;
	return (res);
}

char	*unsigned_to_string(unsigned n)
{
	char			*res;
	unsigned long	number;
	unsigned long	copy;
	int				i;

	number = (unsigned long)n;
	copy = number;
	i = 1;
	while ((copy /= 10))
		i++;
	res = ft_calloc(i-- + 1, sizeof(char));
	while (number >= 10)
	{
		res[i--] = '0' + number % 10;
		number /= 10;
	}
	res[i] = '0' + number % 10;
	return (res);
}

char	*dec_to_hex_string(unsigned number, int type)
{
	char		*hex;
	char		*res;
	unsigned	i;
	unsigned	max;
	unsigned	k;

	hex = ft_strdup(type ? "0123456789abcdef" : "0123456789ABCDEF");
	res = ft_strdup("");
	max = 16;
	while (number >= max)
	{
		i = number / 16;
		k = (number - (i * 16));
		res = ft_strjoin(ft_memset(ft_calloc(2, sizeof(char)), hex[k], 1), res);
		number = i;
	}
	res = ft_strjoin(ft_memset(ft_calloc(2, sizeof(char)), \
		hex[number], 1), res);
	free(hex);
	return (res);
}

char	*long_dec_to_hex_string(long unsigned number)
{
	char			*hex;
	char			*res;
	long unsigned	i;
	long unsigned	max;
	long unsigned	k;

	hex = ft_strdup("0123456789abcdef");
	res = ft_strdup("");
	max = 16;
	while (number >= max)
	{
		i = number / 16;
		k = (number - (i * 16));
		res = ft_strjoin(ft_memset(ft_calloc(2, sizeof(char)), hex[k], 1), res);
		number = i;
	}
	res = ft_strjoin(ft_memset(ft_calloc(2, sizeof(char)), \
		hex[number], 1), res);
	free(hex);
	return (res);
}
