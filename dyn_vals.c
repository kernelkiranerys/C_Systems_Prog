#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int *intPtr = malloc(sizeof(int));
    char *charPtr = malloc(sizeof(char));
    char *strPtr = malloc(sizeof(char) * 50);
    if (intPtr == NULL || charPtr == NULL || strPtr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Type an integer: ");
    scanf("%d", intPtr);
    printf("Type a character: ");
    scanf(" %c", charPtr);
    printf("Type a string: ");
    scanf("%s", strPtr);

    printf("You entered integer: %d\n", *intPtr);
    printf("You entered character: %c\n", *charPtr);
    printf("You entered string: %s\n", strPtr);

    free(intPtr);
    free(charPtr);
    free(strPtr);

}
    