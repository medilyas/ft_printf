/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:35:16 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:37:51 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_data
{
	int		preci;
	int		lenght;
	int		zero;
	int		plus;
	int		minus;
	int		hash;
	int		width;
	int		space;
	char	spec;
}	t_data;

typedef struct s_index
{
	int				i;
	int				start;
	int				nbr_sign;
	int				targlen;
	int				freed;
	char			nul;
	char			*specflag;
	unsigned long	hex;
}	t_index;

char	*ft_free_bonus(char *s);
void	set_data(char *comb, t_data *data);
void	ft_change(char **p);
int		ft_atoi_bonus(char *str);
char	*ft_itoa_bonus(int n);
char	*ft_utoa_bonus(unsigned int n);
char	*do_process(char *comb, char *target, t_index *index);
char	*do_precision(char *target, t_data data);
char	*do_plus_hash(char *target, t_data data);
char	*do_width(char *target, t_data data);
char	*do_space(char *target, t_data data, t_index *index);
char	*add_zeros(char *target, int targlen, t_data data);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_bonus(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup_bonus(const char *s1);
char	*p_render_bonus(unsigned long nbr, char *base);
char	*u_render_bonus(unsigned int nbr);
char	*x_render_bonus(unsigned int nbr, char *base);
char	*c_render_bonus(char c, t_index *index);
char	*s_render_bonus(char *str);
char	*di_render_bonus(int nbr, t_index *index);
int		target_lenght(unsigned long nbr);
void	ft_puthex_bonus(unsigned long nbr, char **target, char *base, int max);
int		ft_strcmp(const char *s1, const char *s2);

#endif
