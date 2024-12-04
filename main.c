#include "get_next_line.h"

#include <fcntl.h>  // For open()
#include <stdio.h>  // For printf()

int main(void)
{
    int     fd;
    char    *line;

    // Open the file for reading
    fd = open("test.txt", O_RDONLY);
    // if (fd < 0)
    // {
    //     perror("Error opening file");
    //     return (1);
    // }

    // Read and print lines until EOF
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line (newline included)
        free(line);         // Free the line after printing
    }

    // Close the file descriptor
    if (close(fd) < 0)
    {
        perror("Error closing file");
        return (1);
    }

    return (0);
}