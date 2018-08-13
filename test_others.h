/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:39:42 by hryu              #+#    #+#             */
/*   Updated: 2018/08/13 13:50:42 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_instr
{
	int		height;
	int		length;
	int		width;
	char	empty;
	char	obst;
	char	full;
}					t_instr;

typedef	struct		s_record
{
	int		x;
	int		y;
	int		max;
}					t_record;

void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
void		ft_strcpy(char *dest, char *str);
void		ft_start(char *str);
int			ft_get_width(char *str, t_instr info, int width);
t_instr		*ft_first_line(char *str);
int			ft_strlen_mod(char *str);
char		*cut_str(char *str, int n);
void		ft_fill_board(t_record *record, char *str, t_instr *info);
void		ft_get_record(t_instr *info, char *str, t_record *record);
int			ft_check_case(char *str, t_instr *info, int position[2], int size);
int			ft_check_square(char *str, int position[2], t_instr *info, int size);
t_record	*ft_new_record(void);
void		ft_put_result(char *str, int start);
void		ft_strconcat(char *dest, char *src, int *size, int buff_size);
int			ft_bigger_sqr(char *str, int position[2], t_instr *info, int size);

#endif
