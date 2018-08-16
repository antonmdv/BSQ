#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef FT_H
# define FT_H

typedef	struct		list
{
	char			c;
	int				numLines;
	struct list		*next;
}					list;

typedef struct		Matrix
{
	int				numOfLines;
	char			emptyChar;
	char			obstacle;
	char			full;
	int				**field;
}					Matrix;

typedef struct		Square
{
	int				row;
	int				col;
	int				sideSize;
}					Square;

list	*importinput(char *file_name);
void	put_char(char c);
void	put_str(char *str);
list	*newNode(char c);
list	*insertNodeEnd(char c, list *l);
Matrix	*transform(list *l);
int		getLineLength(list *l);
Square	*findsquare(Matrix *mtrx);
int		getMin(int a, int b, int c);
char	**transformToRegular(list *l);
void	printBiggestSquare(Matrix *mtrx, Square *sq);
int		inRange(int j, int i, int row, int col, int sideSize);
list	*newNodeLines(int lines);
void	printFirstOccurence(Matrix *mtrx);
#endif
