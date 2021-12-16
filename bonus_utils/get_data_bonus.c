/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:36:55 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/13 17:40:57 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	get_spec_prec(t_data *data, char *comb)
{
	int		i;
	char	*s;

	s = "cspdiuxX%";
	i = -1;
	while (s[++i] != 0)
	{
		if (ft_strrchr(comb, s[i]))
		{
			data->spec = s[i];
			break ;
		}
	}
	if (data->spec == 0)
		data->spec = 'c';
	if (ft_strrchr(comb, '.'))
		data->preci = 1;
}

void	get_lenght(t_data *data, char *comb)
{
	char	*p;
	int		len;
	int		i;

	p = ft_strrchr(comb, '.');
	if (!p)
		return ;
	i = 0;
	len = 0;
	while (p[++i + len])
	{
		while (p[i + len] && p[i + len] >= '0' && p[i + len] <= '9')
			len++;
		if (len)
			break ;
	}
	data->lenght = ft_atoi_bonus(ft_substr(p, 1, len));
}

void	get_lenght_width(t_data *data, char *comb)
{
	int		len;
	int		i;
	int		m;

	m = 0;
	len = 0;
	if (!comb)
		return ;
	i = ft_strlen_bonus(comb);
	while (--i - len >= 0 && comb[i - len])
	{
		if (!m && (comb[i] == '.' || !data->preci))
			m = 1;
		while (m && len <= i && comb[i - len] && comb[i - len] >= '0'
			&& comb[i - len] <= '9' && comb[i - len] != '.')
			len++;
		if (len)
			break ;
	}
	data->width = ft_atoi_bonus(ft_substr(comb, i - len + 1, len));
	get_lenght(data, comb);
}

void	data_init(t_data *data)
{
	data = &((t_data){data->preci = 0, data->lenght = 0,
			data->zero = 0, data->plus = 0, data->minus = 0,
			data->hash = 0, data->width = 0, data->space = 0,
			data->spec = 0});
}

void	set_data(char *comb, t_data *data)
{
	int	i;
	int	m;

	data_init(data);
	get_spec_prec(data, comb);
	get_lenght_width(data, comb);
	m = 1;
	i = -1;
	while (comb[++i])
	{
		if (m && comb[i] >= '1' && comb[i] <= '9')
			m = 0;
		if (comb[i] == '+' && (data->spec == 'd' || data->spec == 'i'))
			data->plus = 1;
		if (comb[i] == '#' && (data->spec == 'x' || data->spec == 'X'))
			data->hash = 1;
		if (comb[i] == '-')
			data->minus = 1;
		if (m && comb[i] == '0'
			&& ((!data->preci && ft_strrchr("diuxX%", data->spec))
				|| ft_strrchr("ps", data->spec)) && !data->minus)
			data->zero = 1;
		if (comb[i] == ' ' && (data->spec == 'd' || data->spec == 'i'))
			data->space = 1;
	}
}
