/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:38:02 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/12 20:37:27 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	slenght(int n, int size)
{
	if (size == 0)
	{
		if (n < 0)
			size++;
		size++;
	}
	if (n >= 10 || n <= -10)
	{
		size++;
		n = n / 10;
		size = slenght(n, size);
	}
	return (size);
}

char	*ft_itoa_bonus(int n)
{
	long	nbr;
	char	*p;
	int		size;

	size = slenght(n, 0);
	p = (char *)malloc(sizeof(char) *(size + 1));
	if (p == 0)
		return (0);
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		p[0] = '-';
	}
	p[size--] = '\0';
	while (nbr >= 10)
	{
		p[size] = nbr % 10 + 48;
		nbr /= 10;
		size--;
	}
	p[size] = nbr % 10 + 48;
	return (p);
}
