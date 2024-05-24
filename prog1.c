// includes in C are like import in JAVA/Python
#include <stdio.h> // bring in all the IO stuff

// Execution starts here
int main(int argc, char** argv) { // argc, number of things in argv, argv is the actual things
    // Tell me how many arguments(sp?) were passed in and what they were
    printf("%d\n",argc);
    for(int i=0; i<argc; i++) {
        printf("%s\n",argv[i]);
    }
    return 0;
}
