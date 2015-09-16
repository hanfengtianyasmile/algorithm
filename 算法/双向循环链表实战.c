//用户输入一个数使得26个字母的排列发送变化

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0


typedef char ElemType;
typedef int Status;

typedef struct DualNode{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode,*DuLinkList;

//初始化链表 
Status InitList(DuLinkList *L){
	DualNode *p,*q;
	int i;
	
	*L = (DuLinkList)malloc(sizeof(DualNode));
	if(!(*L)){
		return ERROR;
	}
	
	(*L)->next = (*L)->prior = NULL;
	
	p = (*L);
	
	
	for(i = 0;i < 26;i++){
		q = (DualNode *)malloc(sizeof(DualNode));
		
		if(!q){
			return ERROR;
		}
		
		q->data = 'A'+i;
		q->prior = p;
		q->next = p->next;
		p->next = q;
		
		p = q;
		
	}
	
	p->next = (*L)->next;
	(*L)->next->prior = p;
	
	return OK;
}

//改变链表指针
void Caesar(DuLinkList *L,int i){
	
	if( i >0 ){
		do{
			(*L) = (*L)->next;
		}while( --i );
	}
	
	if( i < 0 ){
		do{
			(*L) = (*L)->prior;
		}while( ++i );
	}	
	
} 


 
 int main(){
 	
 	DuLinkList L,first;
 	
 	int i,n;
 	
 	InitList(&L);
 	
 	printf("请输入一个整数：");
 	
 	scanf("%d",&n);
 	
 	printf("\n");
 	
 	first = L->next;
 	
 	Caesar(&first,n);
 	
 	for( i=0 ; i < 26 ;i++){
 		
 		printf("%c",first->data);
 		first = first->next;
 	}
 	
 	
 	
 	
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
