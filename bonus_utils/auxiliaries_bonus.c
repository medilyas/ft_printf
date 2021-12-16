/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:39 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:37:35 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_free_bonus(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

int	target_lenght(unsigned long nbr)
{
	unsigned int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		size++;
	}
	return (size);
}

void	ft_puthex_bonus(unsigned long nbr, char **target, char *base, int max)
{
	if (nbr >= 16)
	{
		ft_puthex_bonus(nbr / 16, target, base, --max);
		(*target)[max] = base[nbr % 16];
	}
	else
		(*target)[--max] = base[nbr];
}
