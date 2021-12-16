/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_hash_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:40:13 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/13 16:25:57 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*do_plus_hash(char *target, t_data data)
{
	char	*p;

	if (ft_strchr("di", data.spec) && target[0] != '-' && data.plus)
		p = ft_strjoin("+", target);
	else if (target[0] == '-')
		return (target);
	if ((ft_strchr("xX", data.spec) && data.hash) || data.spec == 'p')
	{
		if ((data.spec == 'x' || data.spec == 'p'))
			p = ft_strjoin("0x", target);
		else if (data.spec == 'X' )
			p = ft_strjoin("0X", target);
	}
	return (p);
}
