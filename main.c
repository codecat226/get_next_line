#include <stdio.h>
#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>

/*Main function: create a test.txt with some text to test out function
Main calls the function in a loop to get each line one at a time.*/

int	main(void)
{
	int		fd;
	char	*file = "test.txt";

	fd = open(file, 0);
	int len = 8;
	for(int i = 0; i < len; i++)
	{
		printf("%s", get_next_line(fd));
	}
	printf("\n");
	close(fd); 
}