#include <stdio.h>
#include <stdlib.h>


#define StackSize 100

typedef int DataType;

typedef struct{
	DataType stack[StackSize];
	int top;
}SeqStack;


//初始化栈
void InitStack(SeqStack *s){
	s->top = 0;  //栈顶指针置为0 
} 


//判断栈是否为空
int StackEmpty(SeqStack *s){
	if(s->top == 0)
		return 1;
	else
		return 0;
} 

//取栈顶元素
 int GetTop(SeqStack *s,DataType *e){
 	if(s->top <= 0){
 		printf("栈已经空\n");
 		return 0;
 	}else{
 		*e = s->stack[s->top-1];
 		return 1;
 	}
 }
 
 
 //将元素入栈
 int PushStack(SeqStack *s,DataType e){
 	if(s->top >= StackSize){
 		printf("栈已满，不能入栈\n");
 		return 0;
 	}else{
 		s->stack[s->top] = e;
 		s->top++;
 		return 1;
 	}
 } 
 //将栈顶元素出栈
 int PopStack(SeqStack *s,DataType *e){
 	if(s->top == 0){
 		printf("栈中已经没有元素，不能进行出栈操作\n");
 		return 0;
 	}else{
 		s->top--;
 		*e = s->stack[s->top];
 		return 1;
 	}
 } 
 
 
 //求栈的长度
 int StackLength(SeqStack *s){
 	return s->top;
 } 
 
 
 //清空栈 
 void ClearStck(SeqStack *s){
 	s->top = 0;
 }
 
 
 
 int main(){
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
