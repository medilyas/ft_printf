/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_render_uxp_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:37:44 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:38:09 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*p_render_bonus(unsigned long nbr, char *base)
{
	char	*target;
	int		targlen;

	targlen = target_lenght(nbr);
	target = (char *)malloc(sizeof(char) * (targlen + 1));
	if (!target)
		return (NULL);
	ft_puthex_bonus(nbr, &target, base, targlen);
	target[targlen] = 0;
	return (target);
}

char	*u_render_bonus(unsigned int nbr)
{
	char	*target;

	target = ft_utoa_bonus(nbr);
	return (target);
}

char	*x_render_bonus(unsigned int nbr, char *base)
{
	char	*target;
	int		targlen;

	targlen = target_lenght(nbr);
	target = (char *)malloc(sizeof(char) * (targlen + 1));
	if (!target)
		return (NULL);
	ft_puthex_bonus(nbr, &target, base, targlen);
	target[targlen] = 0;
	return (target);
}
