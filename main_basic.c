#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

static void run_test(const char *path)
{
    int   fd;
    char *line;
    int   i = 1;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    printf("=== Testing file: %s ===\n", path);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", i, line);
        if (line[0] == '\0')
            printf("(empty line)\n");
        free(line);
        i++;
    }
    printf("=== EOF reached ===\n\n");
    close(fd);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }
    run_test(argv[1]);
    return (0);
}
