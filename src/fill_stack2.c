/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:20:00 by sjang             #+#    #+#             */
/*   Updated: 2017/01/03 18:20:03 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static char     *read_all(const int fd, t_swstacks *sts)
{
    char    *str;
    char    *temp;
    char    arr[201];
    int     size;
    int     sizeall;

    ft_bzero(arr, 201);
    size = 0;
    sizeall = 0;
    str = (char*)malloc(sizeof(char) * 1);
    while ((size = read(fd, arr, 200)) != 0)
    {
        if (size == -1)
            ft_destroy_sts_exit(sts);
        temp = (char*)malloc(sizeof(char) * (sizeall + 1));
        ft_memcpy(temp, str, sizeall);
        free(str);
        str = (char*)malloc(sizeof(char) * (sizeall + size + 1));
        ft_memcpy(str, temp, sizeall);
        ft_memcpy(str + sizeall, arr, size);
        str[sizeall + size] = 0;
        free(temp);
        sizeall += size;
    }
    return (str);
}

static char     **get_splstr(char *file, t_swstacks *sts)
{
    int     fd;
    char    *str;
    char    **splstr;

    fd = open(file, O_RDONLY);
    if (fd < 2)
        ft_destroy_sts_exit(sts);
    str = read_all(fd, sts);
    splstr = ft_strsplit(str, ' ');
    free(str);
    close(fd);
    return (splstr);
}

static void     destroy_splstr(char **splstr)
{
    int i;

    i = 0;
    while (splstr[i])
    {
        free(splstr[i]);
        i++;
    }
    free(splstr);
}

void            ft_get_stack_file(char *file, t_swstacks *sts)
{
    char        **splstr;
    int         i;
    long long   n;

    splstr = get_splstr(file, sts);
    i = 0;
    while (splstr[i])
        i++;
    i--;
    while (i >= 0)
    {
        n = ft_atoll(splstr[i]);
        if (!ft_isonly_digit(splstr[i]) || !ft_isint(n) ||
            ft_stack_where_data(sts->a, n))
            ft_destroy_sts_exit(sts);
        ft_stack_push(sts->a, (int)n);
        i--;
    }
    destroy_splstr(splstr);
}
