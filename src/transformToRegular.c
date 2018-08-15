#include "headers.h"

char **transformToRegular(list *l)
{
	Matrix *mtrx;
	int row;
	int col;
	char **field;
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

	field = (char **)malloc((sizeof(char *) * mtrx->numOfLines)+1);
	field[mtrx->numOfLines] = NULL;

	while (l->next)
	{
		if(l->c == '\n')
		{
			l = l->next;
			col = 0;
			row++;
			lineLength = getLineLength(l);
			field[row] = (char *)malloc((sizeof(char)
						* lineLength)+1);
			field[row][col] = l->c;
			field[row][lineLength] = '\0';
		}
		else
		{
			col++;
                        field[row][col] = l->c;
		}
		l = l->next;
	}

	printf("\n\n\n");
	printCharField(field);

	return (field);
}
