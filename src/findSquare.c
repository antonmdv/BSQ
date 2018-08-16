#include "headers.h"

Square *findSquare(Matrix *mtrx)
{
	Square *sq;
	int  **field;
	int i;
	int j;
	
	sq = malloc(sizeof(Square));
	field = mtrx->field;

	i = 0;
	j = 0;
	sq->row = 0;
	sq->col = 0;
	sq->sideSize = 0;
	

	while(j < mtrx->numOfLines)
	{
		i = 0;
		while(field[j][i] != -1)
		{	
			if(i == 0 || j == 0)
				field[j][i] = field[j][i];	
			
			else if (field[j][i] != 0)
			{
				field[j][i] = 1 + getMin(field[j][i-1],field[j-1][i],field[j-1][i-1]);			
				if(field[j][i] > sq->sideSize)
				{
					sq->sideSize = field[j][i];
					sq->row = j;
					sq->col = i;
				}
			}
			i++;
		}	
		j++;
	}
	return (sq);
}
