// Header file for cats
//  Need the following boiler plate to avoid multiple def problem
#ifndef CATS_H
#define CATS_H

struct cat {
    char* name1;
    char* name2;
    char* name3;
    int age;
};

// constructor/destructor
struct cat* new_cat(char* n, int a);
void destroy_cat(struct cat* cat);

void cat_meow(struct cat* cat);

#endif
