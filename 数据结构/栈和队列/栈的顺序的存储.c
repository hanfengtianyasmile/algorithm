#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

#define STACK_INCR 30

typedef char ElemType;

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



//实战：二进制转化为十进制 
 int main(){
 	ElemType c;
 	sqStack s;
 	int len,i,sum = 0;
 	
 	initStack(&s);
 	
 	printf("请输入二进制数，输入#符号表示结束\n");
 	
 	scanf("%c",&c);
 	
 	while(c != '#'){
 		Push(&s,c);
 		scanf("%c",&c);
 	}
 	
 	getchar();
 	
 	len = StackLen(s);
 	
 	printf("栈的当前容量是: %d\n",len);
 	
 	for(i = 0; i < len;i++){
 		Pop(&s,&c);
 		sum = sum + (c-'0') * pow(2,i);   //不太懂呢 
 	}
 	
 	printf("转化为十进制数是：%d\n",sum);
 	
 	return 0;
 	
 	
 }
 
 
 
 
 
 
 
 
