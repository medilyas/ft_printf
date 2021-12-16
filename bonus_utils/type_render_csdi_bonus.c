/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_render_csdi_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:37:18 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:39:27 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_change(char **p)
{
	int	i;

	i = 0;
	while ((*p)[i] != '^' && (*p)[i])
		i++;
	(*p)[i] = 0;
}

char	*c_render_bonus(char c, t_index *index)
{
	char	*target;

	if (c != 0)
	{
		target = (char *)malloc(sizeof(char) * 2);
		target[0] = c;
		target[1] = 0;
	}
	else
		target = ft_strdup_bonus("^");
	index->nul = c;
	return (target);
}

char	*s_render_bonus(char *str)
{
	char	*target;

	if (!str)
		return (ft_strdup_bonus("(null)"));
	target = ft_strdup_bonus(str);
	return (target);
}

char	*di_render_bonus(int nbr, t_index *index)
{
	char	*target;

	if (nbr < 0)
		index->nbr_sign = -1;
	else
		index->nbr_sign = 1;
	target = ft_itoa_bonus(nbr);
	return (target);
}
