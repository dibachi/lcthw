#include <stdio.h>
#include <ctype.h>

void print_letters(char arg[]){
    int i;

    for (i = 0; arg[i] != '\0'; i++){
        char ch = arg[i];
        int can_print_it = isalpha((int)ch) || isblank((int)ch);
        if (can_print_it){
            printf("'%c' == %d ", ch, ch);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++) {
        print_letters(argv[i]);
    }
    return 0;
}

/* NOTE: this code is the one originally given. gonna try to boil it down
//forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_args(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++){
        print_letters(argv[i]);
    }
}

void print_letters(char arg[])
{
    int i = 0;

    for (i = 0; arg[i] != '\0'; i++){
        char ch = arg[i];

        if (can_print_it(ch)){
            printf("'%c' == %d ", ch, ch);
        }
    }
    printf("\n");
}

int can_print_it(char ch)
{
    return isalpha((int)ch) || isblank((int)ch);
}

int main(int argc, char *argv[])
{
    print_args(argc, argv);
    return 0;
} */