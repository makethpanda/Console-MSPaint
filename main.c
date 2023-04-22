//
// Created by jboud on 12/04/2023.
//
#include <stdio.h>
#include "functions.h"
#include "functions.c"
void runApp() {
    printf("Running the app...\n");
}

void showInstructions() {
    printf("Here are the instructions...\n");
}

int main() {
    int Lshapes[30];
    Point point[30];


    int nb = 0;
    displayMenu(Lshapes, nb);

    return 0;
}
