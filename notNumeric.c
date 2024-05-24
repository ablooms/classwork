#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Want a program that takes the argument and converts to an integer, then displays the int

    //...the characters for the number come in as an argument (will be in argv)
    // Execute as: ./prog 17
    // Should print 17 and exit
    
    // What if the number of arguments isn't right?

    // Get the correct "string"
    char* num = argv[1];
    // Convert the string to an integer
    int inum = atoi(num);
    // print that integer out
    printf("%d\n",inum);
    // Return to the OS that everything worked out ok
    return 0;
}
