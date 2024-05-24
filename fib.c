// IO library
#include <stdio.h>

int main(int argc, char** argv) {
    // compute the fib value for whatever number the user gives me
    // Need to convert argv[1] to an int before assignment
    int n = atoi(argv[1]); // get the first argument... argv[0] is the program name

    long v = fib(n); // compute the answer
    printf("Fib(%d) -> %ld\n",n,v); // print the answer
    return 0;
}
