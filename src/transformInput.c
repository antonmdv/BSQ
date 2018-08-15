#include "headers.h"

Matrix *transform(list *l)
{
	Matrix *mtrx;
	int row;
	int col;
	int **field;
	//char **fieldToPrint;
	int lineLength;

	row = -1;	
	mtrx = malloc(sizeof(Matrix));
	
	//Fill the inputs;
	mtrx->numOfLines = l->c;
	l = l->next;
	mtrx->emptyChar = l->c;
	l = l->next;
	mtrx->obstacle = l->c;
	l = l->next;
	mtrx->full = l->c;
	l = l->next;
	
	field = (int **)malloc((sizeof(int **) * mtrx->numOfLines)+1);	
	field[mtrx->numOfLines] = NULL;
	
	while (l->next)
	{	
		if(l->c == '\n')
		{
			//printf("\n");
			l = l->next;
			col = 0;
			row++;
			lineLength = getLineLength(l);
			field[row] = (int *)malloc((sizeof(int) 
						* lineLength)+1);
			if(l->c == mtrx->obstacle)
				field[row][col] = 0;
			else
				field[row][col] = 1;
			//printf("%d ", field[row][col]);				
			field[row][lineLength] = 10; 
		}
		else
		{
			col++;
			if(l->c == mtrx->obstacle)
                                field[row][col] = 0;
                        else
                                field[row][col] = 1;
			//printf("%d ",field[row][col]);
		}
		l = l->next;					
	}
	mtrx->field = field;
	printf("\n\n\n");	
	printMatrix(field);
	
	return (mtrx);
}
