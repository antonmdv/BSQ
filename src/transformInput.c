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
	
	//Fill the inputs;
	mtrx->numOfLines = l->numLines;
	l = l->next;
	mtrx->emptyChar = l->c;
	l = l->next;
	mtrx->obstacle = l->c;
	l = l->next;
	mtrx->full = l->c;
	l = l->next;
	//l = l->next;
	
		
	printf("\n\nNum of Line=> %d, emptyChar=> %c, obstcle=> %c, full=> %c\n\n", mtrx->numOfLines, mtrx->emptyChar, mtrx->obstacle, mtrx->full);
	
	
	field = (int **)malloc((sizeof(int **) * mtrx->numOfLines)+1);	
	field[mtrx->numOfLines] = NULL;
	
	//printf("\n\nChec 1\n\n");
	
	while (l->next)
	{	
		//printf("%c", l->c);
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
			field[row][lineLength] = -1;
		   	
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
	/*
	printf("\n\nDone Filling\n\n");	
	//printMatrix(field);
	*/
	return (mtrx);
}
