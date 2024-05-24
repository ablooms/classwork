// Want a recursive program that counts down to 0

#include <stdio.h>

void recCount(char n) {
    if(n<1) {
       return;
    } else {
       printf("%hhd\n",n);
       recCount(n-1);
    }
}

void main() {
    char n;
    printf("Enter a number 0-127: ");
    fscanf(stdin,"%hhd",&n);
    recCount(n);
}
