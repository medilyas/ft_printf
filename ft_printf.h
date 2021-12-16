/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:26 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/12 14:42:37 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_free(char *s);
int		ft_printf(const char *input, ...);
size_t	ft_strlen(const char *s);
int		c_render(char c);
int		s_render(char *str);
int		p_render(unsigned long nbr, char *base);
void	ft_putnbr_hex(unsigned long nbr, char *base, int *count);
int		di_render(int nbr);
char	*ft_itoa(int n);
int		u_render(unsigned int nbr);
char	*ft_utoa(unsigned int n);
int		x_render(unsigned int nbr, char *base);

#endif
