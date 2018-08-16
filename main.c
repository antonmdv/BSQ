#include "headers.h"

int main(int argc, char **argv)
{
	list *input;
	Matrix *mtrx;
	Square *sq;
	int i = 0;
	
	i = 1;
	if (argc >= 2)
	{		
		while(argv[i] != NULL)
		{
			input = importInput(argv[i]);
	
			//Check Validity		

			mtrx = transform(input);				
		
			sq = findSquare(mtrx);
			if(sq->sideSize == 1)
				printFirstOccurence(mtrx);
			else 	
				printBiggestSquare(mtrx, sq);
			
			put_char('\n');

			i++;
		}
	}
	else
		put_str("Invslid number or files\n");
	
	return (0);	
}
