/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:20 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/20 12:00:23 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct Node {
    int data;
    int moves;
    struct Node* next;
} Node;

void insertNode(Node** head, int data);
void displayList(Node* head);
void sort_three(Node **n);
int size(Node* stack);
int max(Node* stack);
int min(Node* stack);
int max_of_2_elements(int a,int b);
int index_from_b(int Adata,Node* stackB);
int index_from_a(int Bdata,Node* stackA);
int best_move(Node* stackA, Node* stackB,int* index);
void push_to_b(Node** stackA, Node** stackB,int Adata_to_push ,int index_to_push_from_A_to_B);
void push_to_a(Node** stackA, Node** stackB);
void sort_stack(Node** stackA, Node** stackB);
void rotate_until_sorted(Node** stackA);


void sa(Node** head);
void sb(Node** stackB);
void rotate(Node** head);
void reverse_rotate(Node** head);
void ra(Node** head);
void rb(Node** head);
void rr(Node** a, Node** b);
void rra(Node** head);
void rrb(Node** head);
void rrr(Node** a, Node** b);
void pb(Node** stackA, Node** stackB);
void pa(Node** stackA, Node** stackB);

#endif