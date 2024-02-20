/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:07 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/19 16:50:20 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

void displayList(Node* head) 
{
    Node* current = head;
    while (current != NULL) {
        printf("%d \n", current->data); 
        current = current->next;
    }
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
// void sort_five(Node** stackA, Node** stackB) 
// {
//     int i = 0;
//     while (i < 2) 
//     {
//         int min_index = min(*stackA);
//         int j = 0;
//         while (j < min_index) 
//         {
//             ra(stackA);
//             j++;
//         }
//         pb(stackA, stackB);
//         i++;
//     }
//     sort_three(stackA);

//     pa(stackA, stackB);
//     pa(stackA, stackB);
// }




