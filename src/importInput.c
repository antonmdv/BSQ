
#include "headers.h"

list *importInput(char *fileName)
{
	list *l;
	int  fd;
	char buff;

	l = NULL;

	fd = open(fileName, O_RDONLY);
	
	if (fd == -1)
	{
		put_str("open() error\n");
		return (l);
	}
	
	while (read(fd, &buff, 1))
	{
		if(l == NULL)
			l = newNode(buff);
		else
			l = insertNodeEnd(buff,l);		
	}
	//printList(l);
	close(fd);
	return (l);
}
