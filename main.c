#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd;
	size_t bytes_read;
	size_t count;
	char buffer[100]; // to change

	count = 5; // temporary var declariation
	fd = open("test.txt", O_RDONLY);

	bytes_read = read(fd, buffer, count);

	printf("%s", buffer);
}
