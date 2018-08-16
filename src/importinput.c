/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importInput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:02:15 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 19:30:28 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int			a_to_i(int num, char c)
{
	num *= 10;
	num += (c - 48);
	return (num);
}

list		*importinput(char *file_name)
{
	list	*l;
	int		fd;
	char	buff;
	int		num;

	l = NULL;
	num = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (l);
	while (read(fd, &buff, 1))
	{
		if (buff >= '0' && buff <= '9')
			num = a_to_i(num, buff);
		else
		{
			if (l == NULL)
				l = newNodeLines(num);
			l = insertNodeEnd(buff, l);
		}
	}
	close(fd);
	return (l);
}
