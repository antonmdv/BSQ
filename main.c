/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:27:26 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 22:12:32 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int			main(int argc, char **argv)
{
	list	*input;
	Matrix	*mtrx;
	Square	*sq;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i] != NULL)
		{
			input = importinput(argv[i]);
			//if (input == NULL) print error, move to next file;
			if(input == NULL)
			{
				put_str("map error\n");
			}
			else
			{
				//Check Validity for if(checkMap(input) == 1)
				if(mapvalidity(input) == 1)
				{
					mtrx = transform(input);
					sq = findsquare(mtrx);
					if (sq->sideSize == 1 || sq->sideSize == 0)
						printfirstoccurence(mtrx);
					else
						printbiggestsquare(mtrx, sq);
				}
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
