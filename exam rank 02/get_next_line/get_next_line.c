/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:36:55 by youssama          #+#    #+#             */
/*   Updated: 2022/02/17 23:45:24 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *str = NULL;
    char s = '\0';
    if (BUFFER_SIZE < 0 || fd == -1)
        return 0;
    str = (char *)malloc(9999);
    if (!str)
        return 0;
    int i = 1;
    int k = 0;
    while (s != '\n' && i != 0)
    {
        i = read(fd, &s, 1);
        if (i == -1)
        {
            free(str);
            return 0;
        }
        if (i != 0)
            str[k++] = s;
        str[k]= '\0';
    }
    if (!*str || !str)
    {
        free(str);
        return 0;
    }
    return str;
}

// int main()
// {
//     int fd;
//     fd = open("tst.txt",O_RDONLY);
//     char *t;
//     int i=0;
//     t = get_next_line(fd);
//     while (t != NULL)
//     {
//         printf("%s",t);
//         t = get_next_line(fd);
//         i++;
//     }
//     close(fd);
// }