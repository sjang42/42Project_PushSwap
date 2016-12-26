#include "main.h"

// char	*ft_read_one(void)
// {
// 	char	arr[4];
// 	int		size;
// 	int		i;
// 	t_operators		*op;

// 	ft_bzero(arr, 4);
// 	i = 0;
// 	op = (t_operators*)malloc(sizeof(t_operators));
// 	op->size = 10;
// 	op->operators = (t_sw_operator*)malloc(sizeof(t_sw_operator) * op->size);
// 	while ((size = read(0, arr, 3)))
// 	{
// 		if (size == 1 ||
// 			arr[0] == '\n' || arr[1] == '\n')
// 			ft_exit_error("Wrong operator");

// 		if (size != 2 && arr[2] != '\n')
// 		{
// 			size = read(0, arr + 3, 1);
// 			if (!size && arr[3] != '\n')
// 				ft_exit_error("Wrong operator");
// 			arr[3] = 0;
// 		}
// 		else
// 			arr[2] = 0;
// 		(op->operators)[i] = ft_decide_operator(arr);
// 		if ((op->operators)[i] == 0)
// 		{
// 			ft_destroy_operators(&op);
// 			ft_exit_error("Wrong operator");
// 		}
// 		i++;
// 		ft_bzero(arr, 4);
// 	}
// }


char	*ft_read_one(void)
{
	char	arr[4];
	char	*ret;
	int		size;

	ft_bzero(arr, 4);
	size = read(0, arr, 3);
	if (size == 0)
		return (NULL);
	else if (size == 1)
		ft_exit_error("Wrong operator");
	if (size != 2 && arr[2] != '\n')
	{
		size = read(0, arr + 3, 1);
		if (size != 0 && arr[3] != '\n')
			ft_exit_error("Wrong operator");
		arr[3] = 0;
	}
	else
		arr[2] = 0;
	ret = ft_strdup(arr);
	return (ret);
}
