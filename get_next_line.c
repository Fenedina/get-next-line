#include "get_next_line.h"

char    *ft_read(int fd, static char *str_left)
{
    char    *buf;
    int     i;

    i = 1;
    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (NULL);
    while (!ft_strchr(left_str, '\n') && i != 0)
    {
        i = read(fd, buf, BUFFER_SIZE);
        if (i == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[i] = '\0';
        str_left = ft_strjoin_gnl(str_left, buf);
    }
    free(buf);
    return (str_left);

}

char    *get_next_line(int fd)
{
    char		*new_line;
    static char *str_left;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str_left = ft_read(fd, str_left);
    if (!str_left)
        return (NULL);
    new_line = ft_new_line(str_left);
    str_left = ft_str_left(str_left);
    return (new_line);
}