#include<stdio.h>
#define MAX_STACK 100

typedef int element;
typedef struct {
	int top;
	element data[MAX_STACK];
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	if (s->top == 1)
		return 1;
	else
		return 0;
}

int is_full(StackType* s) {
	if (s->top == MAX_STACK - 1)
		return 1;
	else
		return 0;
}

void push(StackType* s, element item) {
	if (is_full(s) == 1)
		printf("full");
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s) == 1)
		printf("empty");
	else
		return s->data[(s->top)--];
}

element top(StackType* s) {
	if (is_empty(s) == ) {
		printf("empty");
	}
	else
		return s->data[s->top];
}
