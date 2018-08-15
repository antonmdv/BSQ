#include "headers.h"

void printBiggestSquare(char **field, Square *sq)
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
                while(field[j][i] != '\0')
                {
			if(inRange(j, i, row, col, sideSize) == 1)
				put_char('x');
			else
                        	put_char(field[j][i]);
                        i++;
                }
                printf("\n");
                j++;
        }
}
