
#include "push_swap.h"

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