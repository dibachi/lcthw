#include <stdio.h>

/* This is a comment. */
int main(int argc, char *argv[])
{
    int distance = 100;

    //this is also a comment
    printf("You are %d miles away. \n", distance);
    printf("\033[0;35m");
    printf("How did I get here? \n");
    printf("Wasn't I just %d miles over there? \n", distance);
    printf("This is really weird. \nI need to go back. \n");
    printf("\033[0m");
    printf("You are back here. Home again. \n");
    return 0;
}
