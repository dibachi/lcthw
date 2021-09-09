//ex22_main.c
/*
    revised makefile courtesy of "https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/"
*/
#include "ex22.h"
#include "dbg.h"
//testing github on linux

const char *MY_NAME = "Jack A. Dibachi";

void scope_demo(int count)
{
    log_info("count is: %d", count);
    //the bug here is that count is 100 ONLY in the scope of the if statement
    if (count>10) {
        int count = 100; //this is bad. causes bugs!
        log_info("count in this scope is: %d", count);
    }
    //here count goes back to its value within the function scope (the value passed to the function)
    log_info("count is, at exit: %d", count);
    count = 2000;
    log_info("count after assign is: %d", count);
}

int main(int argc, char *argv[])
{
    //test out THE_AGE accessors
    log_info("My name: %s, age: %d", MY_NAME, get_age());
    set_age(100);
    log_info("My age is now: %d", get_age());

    //test out THE_SIZE extern
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();
    //if THE_SIZE is used in multiple programs, this implementation may cause
    //bugs. use accessors (like get_age(), set_age(), etc.) to define these values
    THE_SIZE = 9;
    log_info("THE_SIZE is now: %d", THE_SIZE);
    print_size();

    //test the ratio function static
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("RATIO AGAIN: %f", update_ratio(300.0));

    //test scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);
    log_info("count after calling scope_demo: %d", count);
    return 0;
}