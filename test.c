#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void sa(Node** stackA) 
{
    Node* first = *stackA;
    Node* second = first->next;

    first->next = second->next;
    second->next = first;
    *stackA = second;
    write(1, "sa\n", 3);
}
void sb(Node** stackB)
{
    Node* first = *stackB;
    Node* second=first->next;
    
    first->next = second->next;
    second->next = first;
    *stackB = second;
    write(1, "sb\n", 3);
}
void pb(Node** stackA, Node** stackB)
{
    if (*stackA == NULL) 
    {
        return;
    }
    Node* temp = *stackA;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
    write(1, "pb\n", 3);
}
void pa(Node** stackA, Node** stackB) 
{
    if (*stackB == NULL) 
    {
        return;
    }
    Node* temp = *stackB;
    *stackB = (*stackB)->next;
    temp->next = *stackA;
    *stackA = temp;
    write(1, "pa\n", 3);
}
void ra(Node** head) 
{
    Node* first = *head;
    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    *head = first->next;
    first->next = NULL;
    current->next = first;
    write(1, "ra\n", 3);
}

void rra(Node** head) 
{
    Node* last;
    Node* current = *head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    last = current->next;
    current->next = NULL;
    last->next = *head;
    *head = last;
    write(1, "rra\n", 4);
}
void insertNode(Node** head, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
int size(Node* stack) 
{
    int count = 0;
    Node* temp = stack;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void displayList(Node* head) 
{
    Node* current = head;
    while (current != NULL) {
        printf("%d \n", current->data); 
        current = current->next;
    }
}
int min(Node* stack)
{
    Node *temp = stack;
    int min = temp->data;
    int min_index=0;

    int i = 0;
    while(temp!=NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
            min_index=i;
        }
        i++;
        temp = temp->next;
    }

    return min_index;
}

void sort_three(Node **n)
{
   int a;
   int b;
   int c;

   a = (*n)->data;
   b = (*n)->next->data;
   c =  (*n)->next->next->data;
   if(a > b && a < c)
     sa(n);
   else if (a > b && b > c)
   {
    sa(n);
    rra(n);
   }
   else if (a > c && b < c)
      ra(n);
    else if (a < b && b > c && a > c)
    rra(n);
   else if (a < b && b > c)
   {
    sa(n);
    ra(n);
   }
}
void sort_five(Node** stackA, Node** stackB) 
{
    int i = 0;
    while (i < 2) 
    {
        int min_index = min(*stackA);
        int j = 0;
        while (j < min_index) 
        {
            ra(stackA);
            j++;
        }
        pb(stackA, stackB);
        i++;
    }
    sort_three(stackA);

    pa(stackA, stackB);
    pa(stackA, stackB);
}

int main(int argc, char** argv) {
    Node* stackA = NULL;
    Node* stackB = NULL;
    int i = 1;

    while(i < argc) 
    {
        insertNode(&stackA, atoi(argv[i]));
        i++; 
    }
    if(argc == 4){
        sort_three(&stackA);
    }
    else 
    {
        sort_five(&stackA, &stackB);
    }
    displayList(stackA);

    return 0;
}