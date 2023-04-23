// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"

void displayStack(ShapeNode *top) {
    int index = 0;

    ShapeNode *temp = top;
    while (temp != NULL) {
        printf("Index: %d\n", index);
        printf("Name: %s\n", temp->name);
        printf("Type: ");
        switch (temp->type) {
            case LINE:
                printf("Line\n");
                break;
            case CIRCLE:
                printf("Circle\n");
                break;
            case RECTANGLE:
                printf("Rectangle\n");
                break;
        }
        printf("\n");
        temp = temp->next;
        ++index;
    }
}

void removeByIndex(ShapeNode **top, int index) {
    if (isEmpty(*top)) {
        return;
    } else if (index == 0) {
        pop(top);
    } else {
        int curIndex = 0;
        ShapeNode *curNode = *top;
        ShapeNode *prevNode = NULL;
        while (curNode != NULL && curIndex != index) {
            prevNode = curNode;
            curNode = curNode->next;
            ++curIndex;
        }

        if (curNode != NULL) {
            prevNode->next = curNode->next;
            free(curNode);
        }
    }
}

int main() {
    ShapeNode *stack = initStack();
    int choice;

    while (1) {
        printf("1. Add shape to the stack\n");
        printf("2. Remove shape from the stack by index\n");
        printf("3. Display the entire stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Add shape to the stack
                int shapeType;
                printf("Enter the shape type (0: Line, 1: Circle, 2: Rectangle): ");
                scanf("%d", &shapeType);

                if (shapeType < 0 || shapeType > 2) {
                    printf("Invalid shape type.\n");
                    break;
                }

                char name[50];
                printf("Enter the shape name: ");
                scanf("%s", name);

                if (shapeType == LINE) {
                    Line *lineData = (Line *) malloc(sizeof(Line));
                    printf("Enter the start and end coordinates (x1, y1, x2, y2): ");
                    scanf("%d%d%d%d", &lineData->startX, &lineData->startY, &lineData->endX, &lineData->endY);
                    push(&stack, LINE, strdup(name), (void *) lineData);
                } else if (shapeType == CIRCLE) {
                    Circle *circleData = (Circle *) malloc(sizeof(Circle));
                    printf("Enter the center coordinates (x, y) and radius: ");
                    scanf("%d%d%d", &circleData->centerX, &circleData->centerY, &circleData->radius);
                    push(&stack, CIRCLE, strdup(name), (void *) circleData);
                } else {
                    Rectangle *rectData = (Rectangle *) malloc(sizeof(Rectangle));
                    printf("Enter the start position (x, y), length, and width: ");
                    scanf("%d%d%d%d", &rectData->startX, &rectData->startY, &rectData->length, &rectData->width);
                    push(&stack, RECTANGLE, strdup(name), (void *) rectData);
                }

                printf("Shape added successfully\n");
            } break;

            case 2: {
                // Remove shape from the stack by index
                int index;
                printf("Enter the index to remove: ");
                scanf("%d", &index);
                removeByIndex(&stack, index);
                printf("Shape removed successfully\n");
            } break;

            case 3:
                // Display the entire stack
                displayStack(stack);
                break;

            case 4:
                // Free memory and exit
                freeStack(&stack);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}