/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:41:28 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/13 16:27:47 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*add_space(char *target, t_data data)
{
	char	*p;
	int		i;

	i = -1;
	p = (char *)malloc(sizeof(char) * (data.width + 1));
	if (!p)
		return (NULL);
	if (!data.minus && !ft_strchr("-+", target[0]))
	{
		target[0] = ' ';
		return (target);
	}
	else if (data.minus)
	{
		while (++i < data.width - 1)
			p[i + 1] = target[i];
		p[0] = ' ';
		p[data.width] = 0;
	}
	return (p);
}

char	*do_space(char *target, t_data data, t_index *index)
{
	char	*p;
	int		i;
	int		k;

	p = NULL;
	k = 0;
	if (ft_strchr("di", data.spec) && index->targlen >= data.width
		&& ft_strchr("-+", target[0]))
		return (target);
	if (ft_strchr("di", data.spec) && index->targlen >= data.width)
	{
		p = (char *)malloc(sizeof(char) * (index->targlen + 1));
		if (!p)
			return (NULL);
		i = -1;
		p[++i] = ' ';
		while (++i < index->targlen + 1 && target[k])
			p[i] = target[k++];
		p[i] = 0;
	}
	else if (ft_strchr("di", data.spec) && index->targlen < data.width)
		p = add_space(target, data);
	return (p);
}
