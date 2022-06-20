/*
 * Stack.c
 *
 *  Created on: 11 jun. 2019
 *      Author: galvez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

// Creates an empty stack.
T_Stack create() {
	T_Stack stack = NULL;
	return stack;
}

// Returns true if the stack is empty and false in other case.
int isEmpty(T_Stack q) {
	return q == NULL;	
}

// Inserts a number into the stack.
void push(T_Stack * pq, int operand) {
	T_Stack aux = (T_Stack) malloc(sizeof(T_Node));	

	if (aux == NULL) {
		perror("nosse pudo noseque");	
		exit(-1);
	}

	aux->number = operand;
	aux->next = *pq;

	*pq = aux;
}

int isOperator(char * text){
        return !isdigit(text[0]);
}

int text2Int(char * text) {
        int value=0, i=0;
        while(isdigit(text[i]))
                value = (value*10)+(text[i++]-'0');
        return value;
}

// "Inserts" an operator into the stack and operates.
// Returns true if everything OK or false in other case.
int pushOperator(T_Stack * pq, char operator) {
	int resul, a, b; 
	resul = 0;

	if (isOperator(&operator)) {
		resul = 1;
		pop(pq, &a);
		pop(pq, &b);
		switch (operator) {
			case '+':
				push(pq, a + b);				
				break;
			case '-':
				push(pq, a - b);
				break;
			case '*':
				push(pq, a * b);
				break;
			case '/':
				push(pq, a / b);
				break;
		}
	}

	return resul;
}

// Puts into data the number on top of the stack, and removes the top.
// Returns true if everything OK or false in other case.
int pop(T_Stack * pq, int * data) {
	int resul = 0;

	if (pq != NULL) {
		resul = 1;
		*data = (*pq)->number;
		pq = NULL;
		free(pq);
	}
	
	return resul;
}

// Frees the memory of a stack and sets it to empty.
void destroy(T_Stack * pq) {
	int auxPereza;

	while (!isEmpty(*pq)) {
		pop(pq, &auxPereza);
	}
}
