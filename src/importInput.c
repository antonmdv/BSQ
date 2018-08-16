
#include "headers.h"

list *importInput(char *fileName)
{
	list *l;
	int  fd;
	char buff;
	int num;

	l = NULL;

	fd = open(fileName, O_RDONLY);
	
	if (fd == -1)
	{
		put_str("open() error\n");
		return (l);
	}

	num = 0;
	
	while (read(fd, &buff, 1))
	{
		if(buff >= '0' && buff <= '9')
		{
			num *= 10;
			num +=(buff-48);
		}
		else
		{
			if(l == NULL)
				l = newNodeLines(num);
			l = insertNodeEnd(buff,l);		
		}
	}
	close(fd);
	return (l);
}
