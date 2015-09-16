#include <stdio.h>
#include <stdlib.h>


#define StackSize 100

typedef int DataType;

typedef struct{
	DataType stack[StackSize];
	int top;
}SeqStack;


//��ʼ��ջ
void InitStack(SeqStack *s){
	s->top = 0;  //ջ��ָ����Ϊ0 
} 


//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SeqStack *s){
	if(s->top == 0)
		return 1;
	else
		return 0;
} 

//ȡջ��Ԫ��
 int GetTop(SeqStack *s,DataType *e){
 	if(s->top <= 0){
 		printf("ջ�Ѿ���\n");
 		return 0;
 	}else{
 		*e = s->stack[s->top-1];
 		return 1;
 	}
 }
 
 
 //��Ԫ����ջ
 int PushStack(SeqStack *s,DataType e){
 	if(s->top >= StackSize){
 		printf("ջ������������ջ\n");
 		return 0;
 	}else{
 		s->stack[s->top] = e;
 		s->top++;
 		return 1;
 	}
 } 
 //��ջ��Ԫ�س�ջ
 int PopStack(SeqStack *s,DataType *e){
 	if(s->top == 0){
 		printf("ջ���Ѿ�û��Ԫ�أ����ܽ��г�ջ����\n");
 		return 0;
 	}else{
 		s->top--;
 		*e = s->stack[s->top];
 		return 1;
 	}
 } 
 
 
 //��ջ�ĳ���
 int StackLength(SeqStack *s){
 	return s->top;
 } 
 
 
 //���ջ 
 void ClearStck(SeqStack *s){
 	s->top = 0;
 }
 
 
 
 int main(){
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
