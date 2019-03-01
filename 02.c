/**
 * Humberto Espinosa Dominguez
 * Daniel Saul Chavez Garcia
 * Jesus Antonio Gonzalez Quevedo
 * 
 * Rosa Guadalupe Paredes Juarez - Advanced Programming
 * Declare a struct that requires a pet.
 *  char[] animal
 *  char[] name
 *  int age
 * 
 * Using an array of this struct, develop the functions
 *  insertPet()
 *  deletePet()
 *  printPets()
 *  petManager()
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUFFER 50

typedef struct Pet {
    char animal[BUFFER];
    char name[BUFFER];
    int age;
    struct Pet * next;
} Pet;

void print_instructions() {
    // Printing instructions
    printf("\n");
    printf("1. Insert a Pet\n");
    printf("2. Delete a Pet\n");
    printf("3. Print all pets\n");
    printf("4. Exit the System.\n");
    printf("What do you wish to do?: ");
}

struct Pet * node_pet(char * animal, char * name, int age){
    struct Pet * new_pet;

    new_pet = (struct Pet *)malloc(sizeof(struct Pet));
    strcpy(new_pet->animal, animal);
    strcpy(new_pet->name, name);
    new_pet->age = age;
    new_pet->next = NULL;

    return new_pet;
}

void insert_pet(struct Pet * head, char * animal, char * name, int age){
    if (head->next == NULL){
        head->next = node_pet(animal, name, age);
        return;
    }
}

void delete_pet(struct Pet * head){
    if (head->next->next == NULL){
        free(head->next);
        head->next = NULL;
    } else if (head->next != NULL)
        delete_pet(head->next);
}

void print_pet(struct Pet * head, int num){
    printf("Pet %d : %s, %s of %d years.\n", num, head->name, head->animal, head->age);
    if (head->next != NULL)
        print_pet(head->next, num+1);
}

void pet_manager() {
    // Declaration of variables
    struct Pet * head;
    int pet_count;
    char selection;

    char animal[BUFFER];
    char name[BUFFER];
    int age;

    // Initialization of the pet
    pet_count = 0;

    // Do while for Pet management
    printf("Entering the Pet Management system.\n");
    print_instructions();
    do {
        scanf("%c", &selection);
        fflush(stdin);

        switch (selection){
            case '1': case 'i':
                printf("\n");
                printf("What kind of pet is it?: ");
                scanf("%s", animal);
                printf("What's the name of the pet?: ");
                scanf("%s", name);
                printf("What is the age of the pet?: ");
                scanf("%d", &age);

                if (pet_count == 0){
                    head = node_pet(animal, name, age);
                    pet_count ++;
                } else {
                    insert_pet(head, animal, name, age);
                    pet_count ++;
                }

                print_instructions();
                break;
            case '2': case 'd':
                if (pet_count == 1){
                    free(head);
                    head = NULL;
                    pet_count --;
                } else if (pet_count > 1) {
                    delete_pet(head);
                    pet_count --;
                }

                print_instructions();
                break;
            case '3': case 'p':
                printf("\nThe amount of pets is: %d\n", pet_count);
                if (pet_count > 0)
                    print_pet(head, 1);
                printf("\n");

                print_instructions();                
                break;
            case '4': case 'q':
                printf("Goodbye!\n");
                break;
            default:

                break;
        }

    } while (selection != 'q' && selection != '4');
}

int main() {
    // Entering the system.
    pet_manager();
    return 0;
}