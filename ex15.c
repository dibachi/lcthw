//ex15.c

#include <stdio.h>

int main(int argc, char *argv[]){
    //two arrays
    int ages[] = {22, 25, 59, 58};
    char *names[] = {
        "Jack", "Lexi", "Farid", "Cheryl"
    };

    int count = sizeof(ages)/sizeof(int);
    int i;
    printf("Way 1:\n");
    for (i = 0; i < count; i++){
        printf("%s is %d years old. \n", names[i], ages[i]);
        printf("Name Address: %p Age Address: %p\n", &names[i], &ages[i]);
    }
    
    char **cur_name = names;
    int *cur_age = ages;
    /* int boi = sizeof(*cur_name);
    int pointer_size = sizeof(cur_name);
    printf("Size of pointer: %d Size of boi: %d \n", pointer_size, boi); */
    printf("Way 2:\n");
    for (i = 0; i < count; i++){
        printf("%s is %d years old. \n", *(cur_name + i), *(cur_age + i));
        printf("Name Address: %p Age Address: %p\n", &*(cur_name + i), &*(cur_age + i));
    }

    printf("Way 3:\n");
    for (i = 0; i < count; i++){
        printf("%s is %d years old. \n", cur_name[i], cur_age[i]);
        printf("Name Address: %p Age Address: %p\n", &cur_name[i], &cur_age[i]);
    }

    return 0;
}