//ex8.c

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;

    if (argc == 1){
        printf("The only argument is the execution command: %s \n", argv[0]);
    } else if (argc > 1 && argc < 4){
        printf("Here's your arguments:\n");

        for (i = 1; i < argc; i++){ // i starts at 1 instead of zero to neglect the execution argument
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else{
        printf("You have too many arguments. Work on your anger issues. \n");
    }
    return 0;
}