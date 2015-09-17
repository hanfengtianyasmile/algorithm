#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define STACK_SIZE 100

#define STACK_INCR 30

#define MAXBUFFER 10

typedef double ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

//初始化栈
 
initStack(sqStack *s){
	s->base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if(!s->base)
		exit(0);
		
	s->top = s->base;
	s->stackSize = STACK_SIZE;
}



//入栈 

Push(sqStack *s,ElemType e){
	if(s->top - s->base >= s->stackSize){
		s->base = (ElemType *)realloc(s->base,(s->stackSize + STACK_INCR)*sizeof(ElemType));
		
		if(!s->base)
			exit(0);
			
		s->top = s->base + s->stackSize;   //设置栈顶
		s->stackSize = s->stackSize + STACK_INCR;  //设置栈的最大容量 
		
	}
	
	*(s->top) = e;
	s->top++;

} 


//出栈
Pop(sqStack *s,ElemType *e){
	if(s->top == s->base)
		return;
	*e = *--(s->top);
} 


//清空一个栈
ClearStack(sqStack *s){
	s->top = s->base;
} 



//销毁一个栈
DestoryStack(sqStack *s){
	int i,len;
	len = s->stackSize;
	for(i = len;i>=0;i--){
		free(s->top);
		s->top--;
	}
	
	s->base = s->top = NULL;
	s->stackSize = 0;
	
} 

//栈的当前容量
int StackLen(sqStack s){
	return (s.top - s.base);
} 



//
 int main(){
 	sqStack s;
 	char c;
 	double d,e;
 	char str[MAXBUFFER];
 	int i = 0;
 	
 	initStack(&s);
 	
 	printf("请按逆波兰表达式输入带计算数据，数据与运算符按照空格隔开，以#作为结束标志\n");
	
	scanf("%c",&c);
	
	while( c != '#'){
		while( isdigit(c) || c == '.'){
			str[i++] = c;
			str[i] = '\0';
			if(i >= 10){
				printf("出错，输入的单个数据过大\n");
				return -1;
			}
			
			scanf("%c",&c);
			
			if(c == ' '){
				d = atof(str);
				Push(&s,d);
				i = 0;
				break;
			}
			
		}
		
		
		switch( c ){
			case '+':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d+e);
				break;
			case '-':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d-e);
				break;
			case '*' :
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d*e);
				break;
			case '/' :
				Pop(&s,&e);
				Pop(&s,&d);
				if(e != 0){
					Push(&s,d/e);
				}else{
					printf("\n出错，除数为零\n");
					return -1;
				}		
				break;			
		}
	
		scanf("%c",&c);
		
	} 
 	Pop(&s,&d); 
 	printf("\n最终的计算结果为: %f \n",d);
 	return 0;
 	
 }
 
 
 
 
 
 
 
 
