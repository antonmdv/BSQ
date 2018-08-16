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
list	*newnode(char c);
list	*insertnodeend(char c, list *l);
Matrix	*transform(list *l);
int		getlinelength(list *l);
Square	*findsquare(Matrix *mtrx);
int		getmin(int a, int b, int c);
void	printbiggestsquare(Matrix *mtrx, Square *sq);
int		inrange(int j, int i, Square *sq);
list	*newnodelines(int lines);
void	printfirstoccurence(Matrix *mtrx);
int		mapvalidity(list *l);
#endif
