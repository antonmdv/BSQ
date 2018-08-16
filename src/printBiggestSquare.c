#include "headers.h"

void printBiggestSquare(Matrix *mtrx, Square *sq)
{
	int row = sq->row;
	int col = sq->col;
	int sideSize = sq->sideSize;
	

	int i;
    int j = 0;

        while (mtrx->field[j] != NULL)
        {
                i = 0;
                while(mtrx->field[j][i] != -1)
                {
					if(inRange(j, i, row, col, sideSize) == 1)
						put_char(mtrx->full);
					else
					{
						if(mtrx->field[j][i] == 0)
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
