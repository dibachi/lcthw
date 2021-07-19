#include <stdio.h>
#include <errno.h>
#include <string.h>


extern int errno;

int main(int argc, char *argv[])
{
    int i = 0;
    char alphabet[] = {
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s \n", i, argv[i]);
    }
    
    if (argc == 1) {
        printf("BRO WHAT ARE YOU DOING YOU CAN'T JUST LEAVE IT BLANK \n");
        return 1;
    }
    char test = argv[1][0];
    
    switch (test) {

        case 'a':
            
            for (i = 0; i < 27; i++) {
                printf("%c \n", alphabet[i]);
            }
            break;
        default:
            printf("I just wanna make sure we got here. \n");
            break;
    }
    char *states[] = {
        "CA", "OR", "WI", "MA"
    };
    int num_states = 4;

    for (i = 0; i < num_states; i++) {
        printf("state %d: %s \n", i+1, states[i]);
    }

    return 0;
}