#include "headers.h"

void put_char(char c)
{
	write(1, &c,1);
}

void put_str(char *str)
{
	while(*str != '\0')
	{
		put_char(*str);
		str++;
	}
}

list *newNodeLines(int lines)
{
	list *l;
	l = malloc(sizeof(list));

	l->numLines=lines;
	l->next = NULL;

	return (l);
}

list *newNode(char c)
{
	list *l;
	l = malloc(sizeof(list));

	l->c = c;
	l->next = NULL;

	return (l);
}

list *insertNodeEnd(char c, list *l)
{
	list *node;
	list *tmp;
	
	tmp = l;
	node = newNode(c);

	while(l->next)
		l = l->next;
	l->next = node;

	return (tmp);
}

int getLineLength(list *l)
{
	int i = 0;
	while(l->c != '\n')
	{
		i++;
		l = l->next;
	}
	return (i);	
}

int getMin(int a, int  b, int c)
{
	int min	= a;
	if(min > b)
		min = b;
	if(min > c)
		min = c;
	return min;		
}

int	inRange(int j, int i, int row, int col, int sideSize)
{
	int flag = 0;
	
	int hMin = col - (sideSize-1);
	int hMax = col;

	int vMin = row - (sideSize-1);
	int vMax = row;	

	if((j >= vMin && j <= vMax) && (i >= hMin && i <= hMax))
		flag = 1;	
	return (flag);
}
