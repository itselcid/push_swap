/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:44:22 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/20 12:25:23 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void push_to_b(Node** stackA, Node** stackB,int Adata_to_push ,int index_to_push_from_A_to_B)
{
    int index_b = index_from_b(Adata_to_push, *stackB);
    int difference_stackA_indexA =size(*stackA) - index_to_push_from_A_to_B ;
    int difference_stackB_indexB =size(*stackB) - index_b;
    if(index_to_push_from_A_to_B <=size(*stackA)/2 && index_b <= size(*stackB)/2)
    {
        while(index_to_push_from_A_to_B > 0 && index_b > 0)
            {
                rr(stackA,stackB);
                 index_to_push_from_A_to_B--;
                 index_b--;
            }
            while(index_to_push_from_A_to_B>0)
            {
                ra(stackA);
                index_to_push_from_A_to_B--;
            }
             while(index_b>0)
            {
                rb(stackB);
                index_b--;
            }
    }
       if(index_to_push_from_A_to_B > size(*stackA)/2 && index_b > size(*stackB)/2)
    {
            while(difference_stackA_indexA > 0 && difference_stackB_indexB > 0)
            {
                rrr(stackA,stackB);
                 difference_stackA_indexA--;
                 difference_stackB_indexB--;
            }
            while(difference_stackA_indexA > 0)
            {
                rra(stackA);
                difference_stackA_indexA--;
            }
             while(difference_stackB_indexB>0)
            {
                rrb(stackB);
                difference_stackB_indexB--;
            }
    }
          if(index_to_push_from_A_to_B <= size(*stackA)/2 && index_b > size(*stackB)/2)
    {
            while(index_to_push_from_A_to_B > 0)
            {
                ra(stackA);
                index_to_push_from_A_to_B--;
            }
             while(difference_stackB_indexB>0)
            {
                rrb(stackB);
                difference_stackB_indexB--;
            }
    }
              if(index_to_push_from_A_to_B > size(*stackA)/2 && index_b <= size(*stackB)/2)
    {
            while(difference_stackA_indexA > 0)
            {
                rra(stackA);
                difference_stackA_indexA--;
            }
             while(index_b>0)
            {
                rb(stackB);
                index_b--;
            }
    }
 
}
int index_from_a(int Bdata,Node* stackA)
{
    int index=-1;
    int i=0;
    int l9rib_lkbir = INT_MAX;
    Node* temp = stackA;
    while(stackA)
    {
        if(stackA->data > Bdata && stackA->data < l9rib_lkbir )
        {
            l9rib_lkbir = stackA->data;
            index=i;
        }
        stackA=stackA->next;
        i++;
    }
 
    if(index == -1)
        index = min(temp);
    
    return index;
}
void push_to_a(Node** stackA, Node** stackB)
{
  
    while(*stackB)
    {
         int index_a = index_from_a((*stackB)->data, *stackA);
        int difference_stackA_indexA =size(*stackA) - index_a ;
        if(index_a <=size(*stackA)/2 )
        {
            while(index_a > 0)
            {
                ra(stackA);
                index_a--;
            }
        }
        else if(index_a > size(*stackA)/2)
        {
            while(difference_stackA_indexA > 0)
            {
                rra(stackA);
                difference_stackA_indexA--;
                
            }   
        }
        pa(stackA,stackB);
    }

       
}
void is_sorted(Node** stackA)
{
    Node* temp = *stackA;
    while(temp->next)
    {
        if(temp->data > temp->next->data)
        {
            printf("stackA is not sorted\n");
            return;
        }
        temp = temp->next;
    }
    printf("stackA is sorted\n");

}

void sort_stack(Node** stackA, Node** stackB)
{   
   int index_to_push_from_A_to_B ;
    
    if(size(*stackA)>3)
    {
        pb(stackA,stackB);
    }
    if(size(*stackA)>3)
    {
        pb(stackA,stackB);
    }
    while(size(*stackA)>3)
    {
        int data_with_least_moves=best_move(*stackA,*stackB,&index_to_push_from_A_to_B);
         push_to_b(stackA,stackB,data_with_least_moves,index_to_push_from_A_to_B);
        pb(stackA,stackB);
    }
    sort_three(stackA);
    push_to_a(stackA,stackB);
}
void rotate_until_sorted(Node** stackA)
{
    int index = min(*stackA);
    int difference_stackA_indexA =size(*stackA) - index ;
    if(index <=size(*stackA)/2 )
    {
        while(index > 0)
        {
            ra(stackA);
            index--;
        }
    }
    else if(index > size(*stackA)/2)
    {
        while(difference_stackA_indexA > 0)
        {
            rra(stackA);
            difference_stackA_indexA--;
            
        }   
    }
     
};
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
        sort_stack(&stackA,&stackB);
        rotate_until_sorted(&stackA);
    }
    
    // printf("stackA\n");
    // displayList(stackA);
    is_sorted(&stackA);


    return 0;
}