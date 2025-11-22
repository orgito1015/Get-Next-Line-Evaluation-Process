#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

static void print_and_free(char *label, char *line)
{
    if (!line)
        printf("%s: (NULL)\n", label);
    else
    {
        printf("%s: %s", label, line);
        free(line);
    }
}

int main(void)
{
    int   fd1;
    int   fd2;
    char *line;

    fd1 = open("tests/a.txt", O_RDONLY);
    fd2 = open("tests/b.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return (1);
    }
    printf("=== Multi-FD test ===\n");

    line = get_next_line(fd1);
    print_and_free("fd1 #1", line);

    line = get_next_line(fd2);
    print_and_free("fd2 #1", line);

    line = get_next_line(fd1);
    print_and_free("fd1 #2", line);

    line = get_next_line(fd2);
    print_and_free("fd2 #2", line);

    line = get_next_line(fd2);
    print_and_free("fd2 #3", line);

    line = get_next_line(fd1);
    print_and_free("fd1 #3", line);

    line = get_next_line(fd2);
    print_and_free("fd2 #4", line);

    close(fd1);
    close(fd2);
    return (0);
}
