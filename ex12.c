//ex12.c

#include <stdio.h>

int main(int argc, char *argv[])
{
    char fullname[] = {'J', 'a', 'c', 'k', ' ', 'D', 'i', 'b', 'a', 'c', 'h', 'i', '\0'};
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Jack";
    
    // WARNING: On some systems you may have to change the
    // %ld in this code to a %u since it will use unsigned ints
    printf("Size of an int: %ld\n", sizeof(int));
    printf("Size of areas: %ld\n", sizeof(areas));
    printf("Number of ints in areas: %ld\n", sizeof(areas)/sizeof(int));
    printf("The first area is %d, the second area is %d \n", areas[0], areas[1]);
    printf("Char size: %ld \nName size: %ld \nNumber of Chars: %ld \n", sizeof(char), sizeof(name), sizeof(name)/sizeof(char));
    printf("Name size: %ld \nNumber of chars: %ld \n", sizeof(fullname), sizeof(fullname)/sizeof(char));
    printf("name=\"%s\" and full_name=\"%s\"\n", name, fullname);
    return 0;
}