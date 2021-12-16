/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:41:45 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/13 11:16:59 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*add_left_blanks(char *target, int targlen, t_data data)
{
	char	*p;
	int		i;
	int		k;

	p = (char *)malloc(sizeof(char) * (data.width + 1));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < data.width - targlen)
		p[i] = ' ';
	k = 0;
	while (i < data.width && target[k])
		p[i++] = target[k++];
	p[i] = 0;
	return (p);
}

char	*add_right_blanks(char *target, t_data data)
{
	char	*p;
	int		i;
	int		k;

	p = (char *)malloc(sizeof(char) * (data.width + 1));
	if (!p)
		return (NULL);
	i = 0;
	k = 0;
	while (target[k])
		p[i++] = target[k++];
	while (i < data.width)
		p[i++] = ' ';
	p[i] = 0;
	return (p);
}

char	*do_width(char *target, t_data data)
{
	char	*p;
	int		targlen;

	p = NULL;
	targlen = ft_strlen_bonus(target);
	if (targlen >= data.width)
		return (target);
	if (!data.zero && !data.minus)
		p = add_left_blanks(target, targlen, data);
	else if (data.zero && !data.minus)
		p = add_zeros(target, targlen, data);
	else if (data.minus)
		p = add_right_blanks(target, data);
	return (p);
}
