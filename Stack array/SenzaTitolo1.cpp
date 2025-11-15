#include <stdio.h>
#include <stdlib.h>
#define DIM 5

// VUTO 0 1 2 3 4
// -1   

typedef struct Stack{
	int *array;
	int top;
	int capacita;
}Stack;

void push(Stack *s, int dato){
	if(s->top == s->capacita-1){
		printf("\n Stack pieno! ");
		return;
	}
	s->top++;	
	s->array[s->top] = dato;
	printf("\n Elemento inserito! ");
}

int pop(Stack *s){
	if(s->top == -1){
		printf("\n Stack vuoto! ");
		exit(1);
	}
	int val = s->array[s->top];
	s->top--;
	
	return val;
}


int main(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->array = (int*)malloc(DIM*sizeof(int));
	s->top = -1;
	s->capacita = DIM;
	int val = 0;
	
	push(s, 5);
	push(s, 6);
	push(s, 7);
	push(s, 8);
	push(s, 9);
	push(s, 10);
	
	printf("\n");
	val = pop(s);
	printf("\n Valore: %d", val);
	val = pop(s);
	printf("\n Valore: %d", val);
	val = pop(s);
	printf("\n Valore: %d", val);
	val = pop(s);
	printf("\n Valore: %d", val);
	val = pop(s);
	printf("\n Valore: %d", val);
	val = pop(s);
	printf("\n Valore: %d", val);
	
	free(s->array);
	free(s);
	
	return 0;
}