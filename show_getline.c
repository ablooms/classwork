// Program to show getline use
// Asks the user for a line of text, then prints
// the text out again

#include <stdio.h> // need IO routines
#include <stdlib.h> // needed for free

int main(int argc, char** argv) {
    char* input = 0; // Make a char pointer that
                     // points at the null string
    size_t buflen = 0; // how large is the memory
                    // currently allocated for input
    ssize_t read;   // how many chars were read (may
                    // not match the amount of allocated memory)
                    
    printf("Enter some text please: ");
    read = getline(&input, &buflen, stdin);
    printf("You entered: <text_start>%s<text_end>\n",input);
    printf("getline read %d characters and allocated %d bytes of memory\n",read,buflen);
    printf("Note: getline includes the terminating newline character as part of the string.");
    
    free(input); // finished with the input, free to not leak memory
    return 0;
}
