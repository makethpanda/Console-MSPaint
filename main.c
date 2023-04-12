//
// Created by jboud on 12/04/2023.
//
#include <stdio.h>
#include "functions.h"

void runApp() {
    printf("Running the app...\n");
}

void showInstructions() {
    printf("Here are the instructions...\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                runApp();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}