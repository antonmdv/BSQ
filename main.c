#include "headers.h"

int main(int argc, char **argv)
{
	list *input;
	Matrix *mtrx;
	Square *sq;

	if (argc == 2)
	{		
		//importInput
		input = importInput(argv[1]);
		
		printf("\n\nImport to list done \n\n");

		//toMatrix
		mtrx = transform(input);				
		
		printf("\n\nMatrix DONE\n\n");

		//findSquare
		sq = findSquare(mtrx);
		
		//printf("\nBiggest Square: j=%d i=%d sides=%d\n\n\n", sq->row, sq->col, sq->sideSize);		
		
		//printSqaure
		printBiggestSquare(mtrx->field, sq);
		printf("\nDONE\n");
	}
	else
		put_str("Invslid number or files\n");
	return(0);	
}
