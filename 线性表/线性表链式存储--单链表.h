#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node{
	DataType data;
	struct Node *next;
}ListNode,*LinkList;


//初始化单链表 
void InitList(LinkList head){
	if((head = (LinkList)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	head->next = NULL;
}


//判断单链表是否为空
int ListEmpty(LinkList head){
	if(head->next == NULL)
		return 1;
	else
		return 0;
} 

//按序号查找
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


//按内容查找
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


//定位操作
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

//在第i个位置插入元素e
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
		printf("插入位置错误!");
		return 0;
	}
	
	if((p = (ListNode *)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	p->data = e;
	
	p->next = pre->next;
	pre->next = p;
	return 1;
}
 
 
//删除第i个节点
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
		printf("删除位置有误");
		return 0;
	}
	
	//待删除的节点
	p = p->next;
	pre->next = p->next;
	free(p);
	return 1; 
	
}

//求表长
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


//销毁链表
void DestroyList(LinkList head){
	LinkList *p,*q;
	p = head;
	while(p != NULL){
		q = p;
		p = p->next;
		free(q);
	}
} 
















