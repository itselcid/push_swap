/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:07:40 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/19 16:27:26 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int max(Node* stack)
{
      

    int max = stack->data;
    int max_index=0;
    int i = 0;
    while(stack!=NULL)
    {
        if(stack->data > max)
        {
            max = stack->data;
            max_index=i;
        }
        i++;
        stack = stack->next;
    }
    return max_index;
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

int max_of_2_elements(int a,int b)
{
    if (a > b)
        return a;
    
    return b;
}
int index_from_b(int Adata,Node* stackB)
{
    int index=-1;
    int i=0;
    int l9rib = -555555;
    Node* temp = stackB;
    while(stackB)
    {
        if(stackB->data < Adata && stackB->data > l9rib )
        {
            l9rib = stackB->data;
            index=i;
        }
        stackB=stackB->next;
        i++;
    }
 
    if(index == -1)
        index = max(temp);
    
    return index;
}

int best_move(Node* stackA, Node* stackB,int* index)
{
    int index_a = 0;
    int least_moves = INT_MAX;
    int data_with_least_moves = 0;
    int moves =0;
    Node* tempA = stackA;
    while (tempA)
    {
        
        int index_b = index_from_b(tempA->data, stackB);
        if (index_a <= size(stackA) / 2 && index_b <= size(stackB) / 2)
            moves = max_of_2_elements(index_a, index_b);
        else if (index_a > size(stackA) / 2 && index_b > size(stackB) / 2)
            moves = max_of_2_elements(size(stackA) - index_a, size(stackB) - index_b);
        else if (index_a <= size(stackA) / 2 && index_b > size(stackB) / 2)
            moves = index_a + (size(stackB) - index_b);
        else if (index_a > size(stackA) / 2 && index_b <= size(stackB) / 2)
            moves = index_b + (size(stackA) - index_a);
     

        if (least_moves > moves)
        {
            least_moves = moves;
            data_with_least_moves = tempA->data;
            *index = index_a;
        }
        index_a++;
        tempA = tempA->next;
    }

    return data_with_least_moves;
}
// void push_to_b(Node** stackA, Node** stackB,int Adata_to_push ,int index_to_push_from_A_to_B)
// {
//     int index_b = index_from_b(Adata_to_push, *stackB);
//     int difference_stackA_indexA =size(*stackA) - index_to_push_from_A_to_B ;
//     int difference_stackB_indexB =size(*stackB) - index_b;
//     if(index_to_push_from_A_to_B <=size(*stackA)/2 && index_b <= size(*stackB)/2)
//     {
//         while(index_to_push_from_A_to_B > 0 && index_b > 0)
//             {
//                 rr(stackA,stackB);
//                  index_to_push_from_A_to_B--;
//                  index_b--;
//             }
//             while(index_to_push_from_A_to_B>0)
//             {
//                 ra(stackA);
//                 index_to_push_from_A_to_B--;
//             }
//              while(index_b>0)
//             {
//                 rb(stackB);
//                 index_b--;
//             }
//     }
//        if(index_to_push_from_A_to_B > size(*stackA)/2 && index_b > size(*stackB)/2)
//     {
//             while(difference_stackA_indexA > 0 && difference_stackB_indexB > 0)
//             {
//                 rrr(stackA,stackB);
//                  difference_stackA_indexA--;
//                  difference_stackB_indexB--;
//             }
//             while(difference_stackA_indexA > 0)
//             {
//                 rra(stackA);
//                 difference_stackA_indexA--;
//             }
//              while(difference_stackB_indexB>0)
//             {
//                 rrb(stackB);
//                 difference_stackB_indexB--;
//             }
//     }
//           if(index_to_push_from_A_to_B <= size(*stackA)/2 && index_b > size(*stackB)/2)
//     {
//             while(index_to_push_from_A_to_B > 0)
//             {
//                 ra(stackA);
//                 index_to_push_from_A_to_B--;
//             }
//              while(difference_stackB_indexB>0)
//             {
//                 rrb(stackB);
//                 difference_stackB_indexB--;
//             }
//     }
//               if(index_to_push_from_A_to_B > size(*stackA)/2 && index_b <= size(*stackB)/2)
//     {
//             while(difference_stackA_indexA > 0)
//             {
//                 rra(stackA);
//                 difference_stackA_indexA--;
//             }
//              while(index_b>0)
//             {
//                 rb(stackB);
//                 index_b--;
//             }
//     }
 
// }
    

// void sort_stack(Node** stackA, Node** stackB)
// {   
//    int index_to_push_from_A_to_B ;
    
//     if(size(*stackA)>3)
//     {
//         pb(stackA,stackB);
//     }
//     if(size(*stackA)>3)
//     {
//         pb(stackA,stackB);
//     }
//     while(size(*stackA)>3)
//     {
//         int data_with_least_moves=best_move(*stackA,*stackB,&index_to_push_from_A_to_B);
//         printf("data_with_least_moves = %d\n",data_with_least_moves);
//         printf("index_to_push_from_A_to_B = %d\n",index_to_push_from_A_to_B);
//          push_to_b(stackA,stackB,data_with_least_moves,index_to_push_from_A_to_B);
//         pb(stackA,stackB);
//     }
//     sort_three(stackA);
// }
