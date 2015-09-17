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



//
 int main(){
 	sqStack s;
 	char c;
 	double d,e;
 	char str[MAXBUFFER];
 	int i = 0;
 	
 	initStack(&s);
 	
 	printf("�밴�沨�����ʽ������������ݣ���������������տո��������#��Ϊ������־\n");
	
	scanf("%c",&c);
	
	while( c != '#'){
		while( isdigit(c) || c == '.'){
			str[i++] = c;
			str[i] = '\0';
			if(i >= 10){
				printf("��������ĵ������ݹ���\n");
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
					printf("\n��������Ϊ��\n");
					return -1;
				}		
				break;			
		}
	
		scanf("%c",&c);
		
	} 
 	Pop(&s,&d); 
 	printf("\n���յļ�����Ϊ: %f \n",d);
 	return 0;
 	
 }
 
 
 
 
 
 
 
 
