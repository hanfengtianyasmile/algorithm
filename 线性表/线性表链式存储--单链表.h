#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node{
	DataType data;
	struct Node *next;
}ListNode,*LinkList;


//��ʼ�������� 
void InitList(LinkList head){
	if((head = (LinkList)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	head->next = NULL;
}


//�жϵ������Ƿ�Ϊ��
int ListEmpty(LinkList head){
	if(head->next == NULL)
		return 1;
	else
		return 0;
} 

//����Ų���
ListNode *Get(LinkList head,int i){
	ListNode *p;
	int j;
	
	if(ListEmpty(head))
		return NULL;
	if(1<1)
		return NULL;
	
	j = 0;
	p = head;
	
	while(p->next != NULL && j<i){
		p = p->next;
		j++;	
	}
	if(j == i)
		return p;
	else
		return NULL;
	
} 


//�����ݲ���
ListNode *LocateElem(LinkList head,DataType e){
	ListNode *p;
	p = head->next;
	while(p){
		if(p->data != e)
			p = p->next;
		else
			break; 
	}
	return p;
} 


//��λ����
int LocatePos(LinkList head,DataType e){
	ListNode *p;
	int i;
	if(ListEmpty(head))
		return 0;
	p = head->next;
	i = 1;
	while(p){
		if(p->data == e){
			return 1;
		}else{
			p = p->next;
			i++;	
		}			
	}
	if(!p)
		return 0;
} 

//�ڵ�i��λ�ò���Ԫ��e
int InsertList(LinkList head,int i,DataType e){
	ListNode *pre,*p;
	int j;
	pre = head;
	j = 0;
	
	while(pre->next != NULL && j<i-1){
		pre = pre->next;
		j++;
	}
	if(j != i-1){
		printf("����λ�ô���!");
		return 0;
	}
	
	if((p = (ListNode *)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	p->data = e;
	
	p->next = pre->next;
	pre->next = p;
	return 1;
}
 
 
//ɾ����i���ڵ�
int DeleteList(LinkList head,int i){
	ListNode *pre,*p;
	int j;
	pre = head;
	j = 0;
	while(pre->next != NULL && pre->next->next != NULL && j<i-1){
		pre = pre->next;
		j++;
	}
	if(j != i-1){
		printf("ɾ��λ������");
		return 0;
	}
	
	//��ɾ���Ľڵ�
	p = p->next;
	pre->next = p->next;
	free(p);
	return 1; 
	
}

//���
int ListLength(LinkList head){
	ListNode *p;
	int count = 0;
	p = head;
	while(p->next != NULL){
		p = p->next;
		count++;
	}
	return count;
} 


//��������
void DestroyList(LinkList head){
	LinkList *p,*q;
	p = head;
	while(p != NULL){
		q = p;
		p = p->next;
		free(q);
	}
} 
















