#include <stdio.h>
#include <stdlib.h>


typedef int DataType;

typedef struct Node{
	DataType data;
	struct Node *prior;
	struct Node *next;
}DListNode,*DLinkList;


 //�������
 int InsertDList(DLinkList head,int i,DataType e){
 	DListNode *p,*s;
 	int j;
 	p = head->next;
 	j = 0;
 	while(p != head && j < i){
 		p = p->next;
 		j++;
 	}
 	
 	if(j != i){
 		printf("����λ�ò���ȷ");
 		return 0;
 	}
 	
 	s = (DListNode *)malloc(sizeof(DListNode));
 	
 	if(!s)
 		return -1;
 	
 	s->data = e;
 	s->prior = p->prior;
 	p->prior->next = s;
 	s->next = p;
 	p->prior = s;
 	
 	return 1;
 	
 }
 
 
 //ɾ����i���ڵ�
 int DeleteDList(DLinkList head,int i,DataType *e){
 	DListNode *p;
 	int j;
 	p = head->next;
 	j = 0;
 	while(p != head && j < i){
 		p = p->next;
 		j++;
 	}
 	
 	if(j != i){
 		printf("ɾ��λ�ò���ȷ");
 		return 0;
 	}
 	
 	p->prior->next = p->next;
 	p->next->prior = p->prior;
 	free(p);
 	
 	return 1;
 	
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  

 
