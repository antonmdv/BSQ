#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef FT_H
# define FT_H

typedef	struct		list
{
	char			c;
	struct list		*next;
}					list;

typedef struct		Matrix
{
	int				numOfLines;
	char			emptyChar;
	char			obstacle;
	char			full;
	int				**field;
	char			**fieldToPrint;
}					Matrix;

typedef struct		Square
{
	int				row;
	int				col;
	int				sideSize;
}					Square;

list	*importInput(char *fileName);
void	put_char(char c);
void	put_str(char *str);
list	*newNode(char c);
list	*insertNodeEnd(char c, list *l);
void	printList(list *l);
Matrix	*transform(list *l);
int		getLineLength(list *l);
void	printMatrix(int  **field);
Square	*findSquare(Matrix *mtrx);
int		getMin(int a, int b, int c);
char	**transformToRegular(list *l);
void	printCharField(char **field);
void	printBiggestSquare(int **field, Square *sq);
int		inRange(int j, int i, int row, int col, int sideSize);
#endif
