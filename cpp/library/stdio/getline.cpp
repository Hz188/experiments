#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Please input a line:\n");
    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        perror("getline");
        free(line);
        return 1;
    }

    printf("Read %zd characters: %s", nread, line);

    free(line);
    return 0;
}

/*
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
*/