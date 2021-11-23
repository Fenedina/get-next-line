#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0')
    {
        i += 1;
    }
    return (i);
}

char	*ft_strchr(const char *str, int ch)
{
    int				i;
    char			*str_new;
    int				len;

    i = 0;
    str_new = 0;
    len = ft_strlen(str);
    if (ch > 256)
        ch = ch - 256;
    while (str[i] != ch && i <= len && str[i] != '\0')
    {
        i++;
    }
    if (len < 0)
        return (0);
    if (str[i] == ch)
        str_new = (char *)&str[i];
    return (str_new);
}

char	*ft_strjoin_gnl(char *str_left, char const *buf)
{
    char	*A;
    size_t	i;
    size_t	j;

    i = -1;
    j = 0;
    if (!str_left)
    {
        str_left = (char *)malloc(1 * sizeof(char));
        str_left[0] = '\0';
    }
    if (!str_left || !buf)
        return (NULL);
    A = (char *)malloc(sizeof(char) * (ft_strlen(str_left) + ft_strlen(buf) + 1));
    if (0 == A)
        return (NULL);
    while (str_left[i++] != '\0')
        A[i] = str_left[i];
    while (buf[j] != '\0')
    {
        A[i++] = buf[j++];
    }
    A[i] = '\0';
    free(str_left);
    return (A);
}

char	*ft_new_line(char *str_left)
{
    int		i;
    char	*str;

    i = 0;
    if (!str_left[i])
        return (NULL);
    while (str_left[i] && str_left[i] != '\n')
        i++;
    str = (char *)malloc(sizeof(char) * (i + 2));
    if (!str)
        return (NULL);
    i = 0;
    while (str_left[i] && str_left[i] != '\n')
    {
        str[i] = str_left[i];
        i++;
    }
    if (str_left[i] == '\n')
    {
        str[i] = str_left[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_str_left(char *str_left)
{
    int		i;
    int		j;
    char	*str;

    i = 0;
    while (str_left[i] && str_left[i] != '\n')
        i++;
    if (!str_left[i])
    {
        free(str_left);
        return (NULL);
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(str_left) - (i + 1)));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (str_left[i])
        str[j++] = str_left[i++];
    str[j] = '\0';
    free(str_left);
    return (str);
}
