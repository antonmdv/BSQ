/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:26 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 22:27:32 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		ifmapvalid(list *l)
{
	Matrix *mtrx;
	Square *sq;

	mtrx = transform(l);
	sq = findsquare(mtrx);
	if (sq->sideSize == 1 || sq->sideSize == 0)
		printfirstoccurence(mtrx);
	else
		printbiggestsquare(mtrx, sq);
}

int			main(int argc, char **argv)
{
	list	*input;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i] != NULL)
		{
			input = importinput(argv[i]);
			if (input == NULL)
				put_str("map error\n");
			else
			{
				if (mapvalidity(input) == 1)
					ifmapvalid(input);
				else
					put_str("map error\n");
			}
			i++;
		}
	}
	else
		put_str("map error\n");
	return (0);
}
