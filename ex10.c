//ex10.c

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("ERROR: You need one argument. \n");
        return 1; //ABORT
    }

    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];
        if (letter <= 'z' && letter >= 'a') {
            letter = letter - 32; //converts lowercase to uppercase using ASCII
        }
        switch (letter) {
            //case 'a':
            case 'A':
                printf("%d, 'A'\n", i);
                break;
            //case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;
            //case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;
            //case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;
            //case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;
            //case 'y':
            case 'Y':
                printf("%d: 'Y'\n", i);
                break;
            
            default:
                printf("%d: %c is not a vowel.\n", i, letter);
        }
    }
    return 0;
}