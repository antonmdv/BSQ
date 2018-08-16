/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printFirstOccurence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:56:18 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 19:37:03 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		flag_first(char c)
{
	int flag;

	flag = 1;
	put_char(c);
	return (flag);
}

void	printfirstoccurence(Matrix *mtrx)
{
	int j;
	int i;
	int flag;

	flag = 0;
	j = 0;
	while (mtrx->field[j] != NULL)
	{
		i = 0;
		while (mtrx->field[j][i] != -1)
		{
			if (mtrx->field[j][i] == 1 && flag == 0)
				flag = flag_first(mtrx->full);
			else
			{
				if (mtrx->field[j][i] == 0)
					put_char(mtrx->obstacle);
				else
					put_char(mtrx->emptyChar);
			}
			i++;
		}
		put_char('\n');
		j++;
	}
}
