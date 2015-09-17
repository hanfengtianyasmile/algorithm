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

//��ʼ��ջ
 
initStack(sqStack *s){
	s->base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if(!s->base)
		exit(0);
		
	s->top = s->base;
	s->stackSize = STACK_SIZE;
}



//��ջ 

Push(sqStack *s,ElemType e){
	if(s->top - s->base >= s->stackSize){
		s->base = (ElemType *)realloc(s->base,(s->stackSize + STACK_INCR)*sizeof(ElemType));
		
		if(!s->base)
			exit(0);
			
		s->top = s->base + s->stackSize;   //����ջ��
		s->stackSize = s->stackSize + STACK_INCR;  //����ջ��������� 
		
	}
	
	*(s->top) = e;
	s->top++;

} 


//��ջ
Pop(sqStack *s,ElemType *e){
	if(s->top == s->base)
		return;
	*e = *--(s->top);
} 


//���һ��ջ
ClearStack(sqStack *s){
	s->top = s->base;
} 



//����һ��ջ
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

//ջ�ĵ�ǰ����
int StackLen(sqStack s){
	return (s.top - s.base);
} 



//ʵս��������ת��Ϊʮ���� 
 int main(){
 	ElemType c;
 	sqStack s;
 	int len,i,sum = 0;
 	
 	initStack(&s);
 	
 	printf("�������������������#���ű�ʾ����\n");
 	
 	scanf("%c",&c);
 	
 	while(c != '#'){
 		Push(&s,c);
 		scanf("%c",&c);
 	}
 	
 	getchar();
 	
 	len = StackLen(s);
 	
 	printf("ջ�ĵ�ǰ������: %d\n",len);
 	
 	for(i = 0; i < len;i++){
 		Pop(&s,&c);
 		sum = sum + (c-'0') * pow(2,i);   //��̫���� 
 	}
 	
 	printf("ת��Ϊʮ�������ǣ�%d\n",sum);
 	
 	return 0;
 	
 	
 }
 
 
 
 
 
 
 
 
