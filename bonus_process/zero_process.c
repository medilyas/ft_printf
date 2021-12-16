/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:41:59 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/07 11:27:42 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	do_for_hexa(char **p, char *target, int targlen, t_data data)
{
	int	i;
	int	k;
	int	len;

	i = -1;
	k = 0;
	while ((data.hash || data.spec == 'p') && k < 2)
		(*p)[++i] = target[k++];
	len = data.width - targlen + 1;
	while (len--)
		(*p)[++i] = '0';
	while (i < data.width && target[k])
		(*p)[i++] = target[k++];
	(*p)[i] = 0;
}

void	do_for_di(char **p, char *target, int targlen, t_data data)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	if (target[0] == '+' || target[0] == '-')
	{
		(*p)[++i] = target[k++];
		while (++i <= data.width - targlen)
			(*p)[i] = '0';
		while (i < data.width && target[k])
			(*p)[i++] = target[k++];
	}
	else
	{
		while (++i < data.width - targlen)
			(*p)[i] = '0';
		while (i < data.width && target[k])
			(*p)[i++] = target[k++];
	}
	(*p)[i] = 0;
}

char	*add_zeros(char *target, int targlen, t_data data)
{
	char	*p;
	int		i;
	int		k;

	p = (char *)malloc(sizeof(char) * (data.width + 1));
	if (!p)
		return (NULL);
	if (ft_strchr("csu%", data.spec))
	{
		i = -1;
		while (++i < data.width - targlen)
			p[i] = '0';
		k = 0;
		while (i < data.width && target[k])
			p[i++] = target[k++];
		p[i] = 0;
	}
	else if (ft_strchr("pxX", data.spec))
		do_for_hexa(&p, target, targlen, data);
	else if (ft_strchr("di", data.spec))
		do_for_di(&p, target, targlen, data);
	return (p);
}
