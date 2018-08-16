#include "headers.h"

Matrix *transform(list *l)
{
	Matrix *mtrx;
	int row;
	int col;
	int **field;
	int lineLength;

	row = -1;	
	mtrx = malloc(sizeof(Matrix));
	
	mtrx->numOfLines = l->numLines;
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
			field[row][lineLength] = -1;
		}
		else
		{
			col++;
			if(l->c == mtrx->obstacle)
				field[row][col] = 0;
            else
				field[row][col] = 1;
		}
		
		l = l->next;					
	}
	
	mtrx->field = field;
	return (mtrx);
}
