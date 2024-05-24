// Program that reads in a bunch of animal names and makes corrasponding animals
// then make them make sounds.
#include <stdlib.h>
#include <stdio.h>
#include "cat.h"

// Function that given a filename, will read all the lines and return the right
//    kinds of animals
struct cat** read_file(char* fname, int* len) {
    // Container to hold cats
    struct cat** cats = malloc(sizeof(struct cat*)*20); // 3 is way too small...
    char* buffer = 0;
    size_t bufsize = 0;
    ssize_t chars_read;

    // Open the file
    FILE* f = fopen(fname, "r");
    // loop over the lines
    int yr = 1; // cat's start at 1 year old and get older each cat
    chars_read = getline(&buffer, &bufsize, f);
    while( !feof(f) ) {
        buffer[chars_read-1] = 0;
        //    Make the animal... for now let's just make cats
        // Read first char to determine kind of animal
        printf("%s\n",buffer);
        if('c' == buffer[0]) {
            // TODO: Add logic to actually make a cat
            //printf("Found cat, %s\n",name);
            printf("Found cat!\n");
            struct cat* c = new_cat(buffer,yr);
            cats[yr-1] = c;
            yr++;
        }
        //    Add animal to the "container"
        // Read for next loop iteration
        chars_read = getline(&buffer, &bufsize, f);
    }
    *len = yr-1;
    // close the file
    fclose(f);
    // Return the container
    return cats;
}

int main(int argc, char** argv) {
    int len; // need to know the "array" length
    struct cat** cats = read_file(argv[1],&len);
    for(int i=0; i<len; i++) {
        cat_meow(cats[i]);
    }
    return 0;
}
