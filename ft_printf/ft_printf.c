/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:26:30 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/28 15:21:39 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		str =  "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_printxd(unsigned int nb, int base)
{
	char *hex = "0123456789abcdef";
	char *dec = "0123456789";
	int n;
	int count;

	count = 0;
	if (nb / base != 0)
		count += ft_printxd(nb/base,base);
	n = nb % base;
	if (base == 16)
			count += write(1, &hex[n], 1);
	if (base == 10)
			count += write(1, &dec[n], 1);
	return (count);
}
int printd(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += ft_putchar('-');
	}
	count += ft_printxd(nb, 10);
	return (count);
}

int ft_printf(const char *fmt, ...)
{
	int i;
	int count;
	va_list ap;

	i = 0;
	count = 0;

	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 's')
			{
				count += ft_putstr(va_arg(ap, char *)
			}
			if (fmt[i] == 'd')
			{
				count += printd(va_arg(ap, int) 
			}
			if (fmt[i] == 'x')
			{
				count +=ft_printxp(va_arg(ap, unsigned int), 16)
			}
		}
		else 
		  count += ft_putchar(fmt[i]);
        i++;
    }
    va_end(ap);
    return (count);
}

