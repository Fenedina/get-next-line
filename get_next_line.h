#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char    *get_next_line(int fd);
char    *ft_read(int fd, static char *str_left);

size_t	ft_strlen(const char *str);
char	*ft_new_line(char *str_left);
char	*ft_str_left(char *str_left);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin_gnl(char *str_left, char const *buf);

#endif
