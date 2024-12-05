#include "get_next_line.h" 

int main(void)
{
    int fd = open("test.txt",O_RDONLY);
    char *f ;
    while((f = get_next_line(fd)))
    {
        printf("%s",f);
        free(f);
    }
    return  0 ; 
}