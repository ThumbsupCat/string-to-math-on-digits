#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct StackNode{
	Item elem;
	struct StackNode *next;
}StackNode;

typedef StackNode TCelSt; // Redenumirea unui nod la notatiile din curs 
typedef StackNode *ACelSt; // Redenumirea unui pointer la nod la notatiile din curs

typedef struct Stack{
	StackNode* head;  // Varful stivei
	long size; // Numarul de elemente din stiva
}Stack;

typedef Stack TStiva; // Redenumirea stivei la notatiile din curs
typedef Stack *ASt;//  // Redenumirea unui pointer la stiva la notatiile din curs

Stack* createStack(void){
	// TODO: Cerinta 1
	Stack *newstack = (Stack*) malloc (sizeof(Stack));
	newstack -> head = NULL;
	newstack -> size = 0;
	return newstack; 
}

int isStackEmpty(Stack* stack){
	if (stack -> head == NULL && stack -> size == 0)
		return 1;
	return 0;
}

void push(Stack *stack, Item elem){
	StackNode *newnode = (StackNode*) malloc (sizeof(StackNode));
	StackNode *gothrough = stack -> head;
	newnode -> elem = elem;
	newnode -> next = NULL;
	if(isStackEmpty (stack) == 1) {
		stack -> head = newnode;
	} else {
		newnode -> next = stack -> head;
		stack -> head = newnode;
	}
	stack -> size++;
}

Item top(Stack *stack){	
	// TODO: Cerinta 1
	return stack -> head -> elem;
} 

Item pop(Stack *stack){
	// TODO: Cerinta 1
	StackNode *deleteit = stack -> head;
	Item popped = top(stack);
	stack -> head = stack -> head -> next;
	free(deleteit);
	deleteit = NULL;
	stack -> size--;
	return popped;
}

void destroyStack(Stack *stack){
	while (isStackEmpty(stack) == 0) {
		pop(stack);
	}
	free(stack);
}

#endif 
