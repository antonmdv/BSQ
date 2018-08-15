#include "headers.h"

int main(int argc, char **argv)
{
	list *input;
	Matrix *mtrx;
	//char **field;
	Square *sq;

	if (argc == 2)
	{		
		//importInput
		input = importInput(argv[1]);
		
		//toMatrix
		mtrx = transform(input);		
		
		//Also keep the same input
		//field = transformToRegular(input);		

		//findSquare
		sq = findSquare(mtrx);
		
		printf("\nBiggest Square: j=%d i=%d sides=%d\n\n\n", sq->row, sq->col, sq->sideSize);		
		
		//printSqaure
		printBiggestSquare(mtrx->field, sq);
	}
	else
		put_str("Invslid number or files\n");
	return(0);	
}
