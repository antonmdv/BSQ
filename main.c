#include "headers.h"

int main(int argc, char **argv)
{
	list *input;
	Matrix *mtrx;
	Square *sq;

	if (argc == 2)
	{		
		input = importInput(argv[1]);
		
		mtrx = transform(input);				
		
		sq = findSquare(mtrx);
		
		printBiggestSquare(mtrx, sq);
	}
	else
		put_str("Invslid number or files\n");
	
	return (0);	
}
