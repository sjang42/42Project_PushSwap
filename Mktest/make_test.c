#include "../libft/include/libft.h"
#include <time.h>
#include <stdio.h>

int 	ft_where_arr(int arr[], int size, int data)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return (-1);
}


int main(int argc, char *argv[])
{
	int size;
	int num;
	int fd;
	int *arr;
	int size_arr;

	if (argc < 3 ||
		!ft_isonly_digit(argv[2]))
	{
		ft_putstr("Usage: ./mktest filename size\n");
		return (0);
	}
	fd = open(argv[1], O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG |
						S_IRWXO);
	size = ft_atoi(argv[2]);
	arr = (int*)malloc(sizeof(int) * size);
	size_arr = 0;
	srand(time(NULL));
	while (size_arr < size)
	{
		num = (rand() % 1000) - 500;
		if (ft_where_arr(arr, size_arr, num) == -1)
		{
			write(fd, " ", 1);
			ft_putnbr_fd(num, fd);
			arr[size_arr] = num;
			size_arr++;
		}
	}
	close(fd);
}