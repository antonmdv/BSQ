/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:51:13 by hryu              #+#    #+#             */
/*   Updated: 2018/08/13 13:54:13 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_others.h"
#define BUFF1 1000000
#define BUFF2 8000000

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + '0';
		ft_putchar(nb);
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i] <= 57 && str[i] >= 48)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void	ft_put_result(char *str, int start)
{
	int		i;

	i = 0;
	while (str[start + i])
		i++;
	write(1, &str[start], i);
}

void		ft_get_record(t_instr *info, char *str, t_record *record)
{
	int		position[2];
	int		max;

	position[1] = 0;
	while (position[1] + record->max < info->height)
	{
		position[0] = 0;
		while (position[0] + record->max < info->width)
		{
			max = ft_check_case(str, info, position, record->max);
			if (max > record->max)
			{
				record->max = max;
				record->x = position[0];
				record->y = position[1];
			}
			else if (max < 0)
			{
				if (position[0] + -max < info->width)
					position[0] = position[0] + -max;
			}
			position[0]++;
		}
		position[1]++;
	}
}

int			ft_check_case(char *str, t_instr *info, int position[2], int size)
{
	int		i;
	int		temp;

	i = size + 1;
	while (1)
	{
		if (position[0] + i > info->width)
			return (i - 1);
		else if (position[1] + i - 1 >= info->height)
			return (i - 1);
		temp = ft_check_square(str, position, info, i);
		if (temp > 0)
		{
			i++;
			while (ft_bigger_sqr(str, position, info, i))
				i++;
			return (i - 1);
		}
		else
			return (temp);
	}
}

int			ft_check_square(char *str, int position[2], t_instr *info, int size)
{
	int i;
	int j;
	int start;

	start = info->length + position[0] + (position[1]) * (info->width + 1);
	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < size)
		{
			if (str[start + i + j * (info->width + 1)] == info->obst)
				return (-i);
			else if (str[start + i + j * (info->width + 1)] == '\n')
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

void		ft_fill_board(t_record *record, char *str, t_instr *info)
{
	int		x;
	int		y;
	int		position;

	y = 0;
	position = info->length + record->x + (record->y) * (info->width + 1);
	while (y < record->max)
	{
		x = 0;
		while (x < record->max)
		{
			str[position + x + y * (info->width + 1)] = info->full;
			x++;
		}
		y++;
	}
}

t_record	*ft_new_record(void)
{
	t_record	*new;

	new = (t_record *)malloc(sizeof(t_record));
	if (new)
	{
		new->x = 0;
		new->y = 0;
		new->max = 0;
	}
	return (new);
}

int			ft_strlen_mod(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i > 16)
			return (0);
		i++;
		if (str[i] == '\n')
			return (i + 1);
	}
	return (i);
}

char		*cut_str(char *str, int n)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(*cpy) * (n));
	while (i <= n)
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}

int			check_v(char *str, int a)
{
	int i;
	int b;

	i = 0;
	b = a - 5;
	if (a < 5)
		return (0);
	if ((str[a - 3] == str[a - 2]) || (str[a - 2] == str[a - 4]))
		return (0);
	else if (str[a - 4] == str[a - 3])
		return (0);
	if (b == 0 && str[0] <= 57 && str[0] >= 48)
		return (1);
	while (i <= b)
	{
		if (str[i] > 57 || str[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

t_instr		*ft_first_line(char *str)
{
	t_instr	*ptr;
	int		i;
	char	*str2;
	int		a;

	ptr = NULL;
	a = ft_strlen_mod(str);
	if (check_v(str, a) == 1)
	{
		str2 = (char *)malloc(sizeof(*str2) * 1000);
		ptr = (t_instr *)malloc(sizeof(t_instr) * 1000);
		i = 0;
		str2 = cut_str(str, a - 5);
		ptr->height = ft_atoi(str2);
		ptr->length = a;
		ptr->empty = str[a - 4];
		ptr->obst = str[a - 3];
		ptr->full = str[a - 2];
	}
	return (ptr);
}

int		ft_bigger_sqr(char *str, int position[2], t_instr *info, int size)
{
	int		x;
	int		y;
	int		start;

	x = size - 1;
	y = 0;
	start = info->length + position[0] + (position[1]) * (info->width + 1);
	if (position[0] + size > info->width)
		return (0);
	else if (position[1] + size > info->height)
		return (0);
	while (y < size - 1)
		if (str[start + x + y * (info->width + 1)] == info->empty)
			y++;
		else
			return (0);
	x = 0;
	while (x < size)
		if (str[start + x + y * (info->width + 1)] == info->empty)
			x++;
		else
			return (0);
	return (1);
}

int		ft_get_width(char *st, t_instr inf, int width)
{
	int		i;
	int		c;
	int		lines;

	i = inf.length - 1;
	c = 0;
	lines = 0;
	while (st[++i])
		if (st[i] == '\n')
		{
			if (width != -1 && width != c)
				return (-1);
			width = c;
			c = 0;
			lines++;
		}
		else if (st[i] != inf.empty && st[i] != inf.obst)
			return (-1);
		else if (c == 2147483647)
			return (-1);
		else
			c++;
	if (lines == inf.height)
		return (width);
	return (-1);
}

void	ft_start(char *str)
{
	t_instr		*info;
	t_record	*record;
	int			width;

	info = ft_first_line(str);
	record = ft_new_record();
	if (info)
	{
		width = -1;
		info->width = ft_get_width(str, *info, width);
		if (info->width > 0)
		{
			ft_get_record(info, str, record);
			ft_fill_board(record, str, info);
			ft_put_result(str, info->length);
			free(str);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}

void	ft_strconcat(char *dest, char *src, int *size, int buff_size)
{
	int		i;
	int		c;

	i = 0;
	if ((*size) > buff_size && (*size) % buff_size == 0)
	{
		if (dest[*size - buff_size])
			i = *size - buff_size;
	}
	c = 0;
	while (dest[i])
		i++;
	while (src[c] && c < buff_size)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	while (c >= 0)
	{
		src[c] = '\0';
		c--;
	}
	dest[i] = '\0';
}

void	ft_check_infinity(int *size, char *str, int buf)
{
	if (*size == buf)
	{
		if (ft_strlen_mod(str) == 0)
		{
			ft_putstr("");
			*size = -1;
		}
	}
}

char	*ft_read(int fd, int buff_size)
{
	char	buff[buff_size + 1];
	char	*str;
	char	*temp;
	int		size;

	size = 0;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	temp = (char*)malloc(sizeof(*str) * (size + 1));
	str[0] = 0;
	temp[0] = 0;
	while (read(fd, buff, buff_size) && str && temp && size >= 0)
	{
		size += buff_size;
		ft_strcpy(temp, str);
		free(str);
		str = (char*)malloc(sizeof(*str) * (size + 1));
		ft_strcpy(str, temp);
		ft_strconcat(str, buff, &size, buff_size);
		str[size] = '\0';
		free(temp);
		temp = (char*)malloc(sizeof(*temp) * (size + 1));
		ft_check_infinity(&size, str, buff_size);
	}
	free(temp);
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		fd;

	str = NULL;
	i = 0;
	if (argc != 1)
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 0)
			{
				str = ft_read(fd, BUFF2);
				ft_start(str);
				close(fd);
			}
			else
				ft_putstr("map error\n");
		}
	else
	{
		str = ft_read(0, BUFF1);
		ft_start(str);
	}
	return (0);
}
