#include <stdio.h>
#define MAXSIZE 1000
#define VALUE 9999

typedef struct minStack{
	int data[MAXSIZE];
	int min;
	int top;
}minStack;

minStack myStack;

int min(minStack *s){
	return s->min;
}

void push(int n,minStack *s){
	if(s->min == VALUE){
		s->data[++(s->top)] = 0;
		s->min = n;
	} else if(n < s->min){
		s->data[++(s->top)] = n- s->min;
		s->min = n;
	} else {
		s->data[++(s->top)] = n - s->min;
	}
}

int pop(minStack *s){
	if(s->top < 0) return VALUE;
	int topV;
	if(s->data[s->top] < 0){
		topV = s->min;
		s->min = s->min - s->data[s->top]; 
	} else {
		topV = s->min + s->data[s->top];
	}
	s->top--;
	return topV;
}

main(){

    myStack.top = -1;
    myStack.min = VALUE;
    push(4, &myStack);
    push(2, &myStack);
    push(3, &myStack);
    push(9, &myStack);
    push(1, &myStack);
    push(8, &myStack);

    printf("+++++++++++++++++++++++++++++++\n");
    int i;
    for(i = 0; i < 6; i++){
        printf("topV = %d , min = %d\n", pop(&myStack), min(&myStack));
    }
    printf("+++++++++++++++++++++++++++++++\n");
}





