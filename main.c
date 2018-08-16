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
			input = importinput(argv[i]);
			
			//if (input == NULL) print error, move to next file;
		
			//Check Validity for if(checkMap(input) == 1)		

			mtrx = transform(input);				
		
			sq = findsquare(mtrx);

			if(sq->sideSize == 1)
				printfirstoccurence(mtrx);
			else 	
				printbiggestsquare(mtrx, sq);
			
			put_char('\n');

			i++;
		}
	}
	else
		put_str("Invslid number or files\n");
	
	return (0);	
}
