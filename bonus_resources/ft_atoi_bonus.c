/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:19:31 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:35:27 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_asign(unsigned long *nbr, int *i, int *signe, char **str)
{
	*nbr = 0;
	*i = 0;
	*signe = 1;
	while ((*str)[*i] == 32 || ((*str)[*i] >= 9 && (*str)[*i] <= 13))
		i++;
}

int	ft_atoi_bonus(char *str)
{
	int				i;
	int				signe;
	unsigned long	nbr;

	if (!str)
		return (0);
	ft_asign(&nbr, &i, &signe, &str);
	if (str[i] == '+' || str[i] == '-' )
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i++] - '0') + (nbr * 10);
		if (nbr > 9223372036854775807lu && signe == -1)
			return (0);
		else if (nbr >= 9223372036854775807lu && signe == 1)
			return (-1);
	}
	if (str)
		free(str);
	return (nbr * signe);
}
