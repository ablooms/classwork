// Objecty code for modeling a cat in a non-OOP language
#include <stdio.h>
#include <stdlib.h> // Need this for malloc

// Define what a cat's attributes are... This is done with a struct
struct cat {
    int age;
    int speed;
};

// Define what a cat can do
void cat_meow(struct cat* self) {
    // Display to the user
    printf("The %d year old cat meows\n",self->age);
    // age the cat after meow
    self->age = self->age+1;
}

// Make a cat and have it meow a few times
int main(int argc, char** argv) {
    // make the cat -- Cat cat = new Cat();
    struct cat* wiskers = (struct cat*)malloc(sizeof(struct cat));
    wiskers->age = 2;
    wiskers->speed = 100;
    // display the age
    printf("Wiskers is %d\n",wiskers->age);
    // meow 3 times
    cat_meow(wiskers);
    cat_meow(wiskers);
    cat_meow(wiskers);
    // display the age
    printf("Wiskers is %d\n",wiskers->age);
    return 0;
}
