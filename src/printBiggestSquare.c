#include "headers.h"

void printBiggestSquare(int **field, Square *sq)
{
	int row = sq->row;
	int col = sq->col;
	int sideSize = sq->sideSize;
	
	/*
	row = 0;
	col = 0;
	sideSize = 0;
	*/



	int i;
    int j = 0;

        while (field[j] != NULL)
        {
                i = 0;
                while(field[j][i] != 10)
                {
					if(inRange(j, i, row, col, sideSize) == 1)
						printf("x");
					else
						if(field[j][i] == 0)
							printf("o");
						else
                        	printf(".");
                        i++;
                }
                printf("\n");
                j++;
        }
}
