//
// Created by julien on 23/04/2023.
//
#include <stdio.h>
#include <stdlib.h>

// Type of shape
typedef enum {
    LINE,
    CIRCLE,
    RECTANGLE
} ShapeType;

// Line shape
typedef struct {
    int startX, startY;
    int endX, endY;
} Line;

// Circle shape
typedef struct {
    int centerX, centerY;
    int radius;
} Circle;

// Rectangle shape
typedef struct {
    int startX, startY;
    int length, width;
} Rectangle;

// Stack element
typedef struct shapeNode {
    ShapeType type;
    char *name;
    void *data; // Can reference any shape
    struct shapeNode *next;
} ShapeNode;

// Stack functions
// Stack functions

// Initialize stack
ShapeNode* initStack() {
    return NULL; // Empty stack is represented by NULL
}

// Check if stack is empty
int isEmpty(ShapeNode *top) {
    return top == NULL;
}

// Push a shape onto the stack
void push(ShapeNode **top, ShapeType type, char *name, void *data) {
    ShapeNode *newNode = (ShapeNode *)malloc(sizeof(ShapeNode));
    newNode->type = type;
    newNode->name = name;
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Pop a shape from the stack
void *pop(ShapeNode **top) {
    if (isEmpty(*top)) {
        printf("Stack is empty.\n");
        return NULL;
    }

    ShapeNode *temp = *top;
    void *data = temp->data;
    *top = (*top)->next;
    free(temp);

    return data;
}

// Peek at the top shape of the stack
ShapeNode *peek(ShapeNode *top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return NULL;
    }

    return top;
}

// Free stack memory
void freeStack(ShapeNode **top) {
    while (!isEmpty(*top)) {
        pop(top);
    }
}