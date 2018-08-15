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

void printList(list *l)
{
	while(l->next)
	{
		put_char(l->c);
		l = l->next;
	}
	put_char(l->c);
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

void printMatrix(int **field)
{
	int i;
	int j = 0;
	
	while (field[j] != NULL)
	{
		i = 0;
		while(field[j][i] != 10)
		{
			printf("%d   ", field[j][i]);
			i++;
		}
		printf("\n");	
		j++;
	}
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

void printCharField(char **field)
{
	int i;
        int j = 0;

        while (field[j] != NULL)
        {
                i = 0;
                while(field[j][i] != '\0')
                {
                        put_char(field[j][i]);
                        i++;
                }
                printf("\n");
                j++;
        }
}

int	inRange(int j, int i, int row, int col, int sideSize)
{
	int flag = 0;
	
	int hMin = col - (sideSize-1);
	int hMax = col;

	int vMin = row - (sideSize-1);
	int vMax = row;
	
	//printf("\n\nhMin=%d  hMax=%d  vMin=%d vMax=%d\n\n",hMin, hMax, vMin, vMax);

	if((j >= vMin && j <= vMax) && (i >= hMin && i <= hMax))
		flag = 1;	
	return (flag);
}
