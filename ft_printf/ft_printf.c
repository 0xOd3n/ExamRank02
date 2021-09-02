/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:59:34 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/02 15:10:12 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t	bytes_len(unsigned int n, int bs)
{
	size_t	len;

	len = (n == 0);
	while (n)
	{
		n = n / bs;
		len++;
	}
	return (len);
}

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_itoa(long int n)
{
	unsigned long int	num;
	size_t				len;
	char				*str;

	num = n;
	if (n < 0)
		num = n * -1;
	len = (n < 0) + bytes_len(num, 10);
	str = (char *)malloc(len + 1);
	str[len--] = '\0';
	if (str && n == 0)
		str[len] = '0';
	while (str && num > 0)
	{
		str[len--] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_hex(long int n)
{
	unsigned int	num;
	size_t				len;
	char				*str;

	num = n;
	len = bytes_len(num, 16);
	str = (char *)malloc(len + 1);
	str[len--] = '\0';
	if (str && n == 0)
		str[len] = '0';
	while (str && num > 0)
	{
		if ((num % 16) < 10)
			str[len--] = (num % 16) + '0';
		else
			str[len--] = ((num % 16) + 39) + '0';
		num = num / 16;
	}
	return (str);
}

int	write_str(const char **format, va_list arg)	
{
	int 	count;
	char	*str;

	count = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
		count += write(1, "(null)", 6);
	while (str && *str != '\0')
		count += write(1, str++, 1);
	(*format)++;
	return (count);
}

int	write_dec(const char **format, va_list arg)	
{
	int 	count;
	char	*str;
	
	count = 0;
	str = ft_itoa(va_arg(arg, int));
	while (*str)
		count += write(1, str++, 1);
	if (*str)
		free(str);
	(*format)++;
	return (count);
}

int	write_hex(const char **format, va_list arg)	
{
	int count;
	char	*str;

	count = 0;
	str = ft_itoa_hex(va_arg(arg, int));
	while (*str)
		count += write(1, str++, 1);
	if (*str)
		free(str);
	(*format)++;
	return (count);
}

int	mk_funct(const char **format, va_list arg)
{
	int	count;

	count = 0;
	if (**format == 's')
		count += write_str(format, arg);
	else if (**format == 'd')
		count += write_dec(format, arg);
	else if (**format == 'x')
		count += write_hex(format, arg);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int 	count;
	va_list	arg;

	va_start(arg, format);
	count = 0;
	while (format && *format)
	{
		if (*format == '%' && format++)
			count += mk_funct(&format, arg);
		count += write(1, format++, 1);
	}
	va_end(arg);
	return (count);
}
