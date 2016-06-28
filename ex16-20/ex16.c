#include <stdio.h> // main
#include <assert.h> // gives the ability to assert that whta it should equal
#include <stdlib.h> // ability to create a struct?
#include <string.h> // strdup?

// create the structure to take 4 arguments
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// function to begin the creation of the individual
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // use malloc to get some raw memory depending on the size of Person
    struct Person *who = malloc(sizeof(struct Person));
    
    // make sure that the memory is valid and isn't a null
    assert(who != NULL);
    
    // initialize each piece of the structure using x->y syntax saying
    // what part of the structure I want to set
    // strdup to duplicate the string
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;
    
    return who;
}

// destroy the structure back to 0
void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    
    free(who->name);
    free(who);
    
    printf("Destoyed struct.\n");
}

// print out what is inside of the structure
void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

// main function
int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
        "Joe Alex", 20, 72, 180);
        
    struct Person *frank = Person_create(
        "Frank Blank", 20, 72, 180);
            
    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);
    
    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);
    
    //make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);
    
    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);
    
    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);
    
    return 0;
}