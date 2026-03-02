#include <stdio.h>

int main(void) {
    FILE *fp = fopen("test.txt", "r");
    fputc('a', fp);
    
    if (ferror(fp)) {
        printf("The file is opened for reading\n");
    }
    
