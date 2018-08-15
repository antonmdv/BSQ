#include "headers.h"

Square *findSquare(Matrix *mtrx)
{
	Square *sq;
	char emptyChar;
	char obstacle;
	char full;
	int  **field;
	int i;
	int j;
	
	sq = malloc(sizeof(Square));
	emptyChar = mtrx->emptyChar;
	obstacle = mtrx->obstacle;
	full = mtrx->full;
	field = mtrx->field;
	
	i = 0;
	j = 0;
	sq->row = 0;
	sq->col = 0;
	sq->sideSize = 0;

	while(field[j] != NULL)
	{
		i = 0;
		while(field[j][i] != 10)
		{
			
			if(i == 0 || j == 0)
				field[j][i] = field[j][i];	
			else if (field[j][i] != 0)
			{
				field[j][i] = 1 + getMin(field[j][i],field[j][i-1],field[j-1][i],field[j-1][i-1]);			
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
 	
	printf("\n\n\n");
	printMatrix(field);
	printf("\n\n\n");
	return (sq);
}
