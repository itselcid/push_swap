
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode(Node** head, int data);
void displayList(Node* head);
int min(Node* stack);
void sort_three(Node **n);
void pb(Node** stackA, Node** stackB);

void sa(Node** head);
void sb(Node** stackB);
void ra(Node** head);
void rra(Node** head);
void pb(Node** stackA, Node** stackB);
void pa(Node** stackA, Node** stackB);

#endif