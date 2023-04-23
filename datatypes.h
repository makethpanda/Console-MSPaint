//
// Created by leila on 23/04/2023.
//

#ifndef CONSOLE_MSPAINT_DATATYPES_H
#define CONSOLE_MSPAINT_DATATYPES_H

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
ShapeNode* initStack();
int isEmpty(ShapeNode *top);
void push(ShapeNode **top, ShapeType type, char *name, void *data);
void *pop(ShapeNode **top);
ShapeNode *peek(ShapeNode *top);
void freeStack(ShapeNode **top);

#endif //CONSOLE_MSPAINT_DATATYPES_H
