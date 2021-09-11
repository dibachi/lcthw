//ex23.c
#include <stdio.h>
#include <string.h>
#include "dbg.h"

#define LENGTH 995

int normal_copy(char *from, char *to, int count)
{
    int i = 0;
    for (i=0; i<count; i++) {
        to[i] = from[i];
    }
    return i;
}

int duffs_device(char *from, char *to, int count)
{
    {
        int n = (count + 7)/8;
        switch (count%8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    log_info("Hey dude. 7.");
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    log_info("Hey dude. 3.");
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;
                } while (--n > 0);
        }
    }
    log_info("Hey this works.");
    return count;
}

int zeds_device(char *from, char *to, int count)
{
    {
        int n = (count + 7)/8;

        switch (count%8) {
            case 0:
again:      *to++ = *from++;

            case 7:
            *to++ = *from++;
            case 6:
            *to++ = *from++;
            case 5:
            *to++ = *from++;
            case 4:
            *to++ = *from++;
            case 3:
            *to++ = *from++;
            case 2:
            *to++ = *from++;
            case 1:
            *to++ = *from++;
            if (--n>0)
                goto again;
        }
    }
    log_info("Hey Zed's thing works, too.");
    return count;
}

int valid_copy(char *data, int count, char expects)
{
    int i = 0;
    for (i=0; i<count; i++) {
        if (data[i] != expects) {
            log_err("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char from[LENGTH] = { 'a' };
    char to[LENGTH] = { 'c' };
    int rc = 0;

    //setup the from to have some stuff
    memset(from, 'x', LENGTH);
    //set it to a failure mode
    memset(to, 'y', LENGTH);
    check(valid_copy(to, LENGTH, 'y'), "Not initialized properly.");

    //use normal copy to
    rc = normal_copy(from, to, LENGTH);
    check(rc == LENGTH, "Normal copy failed: %d", rc);
    check(valid_copy(to, LENGTH, 'x'), "Normal copy failed.");

    //reset
    memset(to, 'y', LENGTH);

    //duffs version
    rc = duffs_device(from, to, LENGTH);
    check(rc == LENGTH, "Duff's device failed: %d", rc);
    check(valid_copy(to, LENGTH, 'x'), "Duff's device failed copy.");

    //reset
    memset(to, 'y', LENGTH);

    //zeds version
    rc = zeds_device(from, to, LENGTH);
    check(rc==LENGTH, "Zed's device failed: %d", rc);
    check(valid_copy(to, LENGTH, 'x'), "Zed's device failed copy.");

    return 0;
error:
    return 1;
}