/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpFunctions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:58:37 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 21:24:50 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		getlinelength(list *l)
{
	int i;

	i = 0;
	while (l->c != '\n')
	{
		i++;
		l = l->next;
	}
	return (i);
}

int		getmin(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int		inrange(int j, int i, Square *sq)
{
	int flag;
	int hmin;
	int hmax;
	int vmin;
	int vmax;

	flag = 0;
	hmin = sq->col - (sq->sideSize - 1);
	hmax = sq->col;
	vmin = sq->row - (sq->sideSize - 1);
	vmax = sq->row;
	if ((j >= vmin && j <= vmax) && (i >= hmin && i <= hmax))
		flag = 1;
	return (flag);
}
