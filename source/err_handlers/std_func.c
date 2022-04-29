#include "err_handlers.h"

int	ft_open(const char *path, int oflag)
{
	int fd;

	fd = open(path, oflag);
	if (fd < 0)
	{
		strerror(errno);
		exit(1);
	}
	return (fd);
}

int	err_exit(const char *msg, int code)
{
	ft_putendl_fd(msg, 2);
	exit(code);
}

void	*ft_malloc(size_t size)
{
	void	*res;
	res = malloc(size);
	if (res == NULL)
		err_exit("Error Malloc", 1);
	return (res);
}
