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
					{	
						//printf("%c",mtrx->full);
						put_char(mtrx->full);
					}
					else
					{
						if(mtrx->field[j][i] == 0)
						{	
							//printf("%c", mtrx->obstacle);
							put_char(mtrx->obstacle);
						}
						else
						{
                        	//printf("%c", mtrx->emptyChar);
                   			put_char(mtrx->emptyChar);
						}
					 }
						i++;
                }

                //printf("\n");
                put_char('\n');
				j++;
        }
}
