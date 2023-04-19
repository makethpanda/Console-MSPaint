//
// Created by jboud on 12/04/2023.
//
#include <stdio.h>
#include "functions.h"

typedef struct {
    int pos_x;
    int pos_y;
}Point;

typedef struct stack {
    struct Point;
};


void addshape(int list[]){
    int choice = 0;
    printf("1- Add a point\n");
    printf("2- Add a line\n");
    printf("3- Add a circle\n");
    printf("4- Add a square\n");
    printf("5- Add a rectangle\n");
    printf("6- Add a poygon\n");
    printf("7- return to previous menu\n");
    scanf("%d", &choice);
    while (choice < 1 || choice > 7) {
        printf("Invalid value, try again :\n");
        scanf("%d", &choice);
    }
    if (choice == 7){
        displayMenu(list);
    }
    if (choice == 1){
        int x,y;
        printf("give the coordinate of x and y :\n");
        scanf("%d %d", &x,&y);


    }
    if (choice == 2){
        displayMenu(list);
    }
    if (choice == 3){
        displayMenu(list);
    }
    if (choice == 4){
        displayMenu(list);
    }
    if (choice == 5){
        displayMenu(list);
    }
if (choice == 6){
displayMenu(list);
}

}


void displaylist(){

}


// Function to display the menu options
void displayMenu(int list[]) {
    int choice = 0;
    printf("Please choose an option :\n");
    printf("1. Add a shape\n");
    printf("2. Display the list of shapes\n");
    printf("3. Delete a shape\n");
    printf("4. Drawing the shapes \n");
    printf("5. Help \n");
    scanf("%d",&choice);
    while (choice < 1 || choice > 5){
        printf("Invalid value, try again :\n");
        scanf("%d",&choice);
    }
    if (choice == 1){
        addshape(list);
    }
    if (choice == 2){
        displaylist();
    }
}


void makecircle(int x, int z, int y)
{
    int i, j;
    for (i = -x; i <= x; i++)
    {
        for (j = -x; j <= x; j++)
        {
            int distance = (i - z) * (i - z) + (j - y) * (j - y);
            int radiusSquared = x * x;
            if (distance <= radiusSquared)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }}



