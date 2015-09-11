#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node * next;  //指针指向下一个节点 
}List;

List L,*Ptrl;

void main(void){
	
}

//计算单链表长度 
int Length(List *Ptrl){
	List * p = Ptrl;
	int j = 0;
	while(p){
		p = p->next;
		j++;
	}
	return j;
}


//查找，按序号
List * FindKth(int k,List * Ptrl){
	List * p = Ptrl;
	int i = 1;
	while(p != NULL && i < k){
		p = p->next;
		i++;
	}
	if( i == k)
		return p;
	else
		return NULL;
} 


//查找，按照值查找
List * Find(int x,List * Ptrl){
	List * p = Ptrl;
	while(p != NULL && p->data != x)
		p = p->next;
	return p;
} 

//插入操作
List * Insert(int x,int i,List * Ptrl){
	List *p,*s;
	if(i == 1){
		s = (List *)malloc(sizeof(List));
		s->data = x;
		s->next = Ptrl;
		return s; 
	}
	p = FindKth(i-1,Ptrl);
	if(p == NULL){
		printf("参数错了，找不到呢");
		return NULL;
	}else{
		s = (List *)malloc(sizeof(List));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return Ptrl;
	}
}

//删除操作
List * Delete(int i,List * Ptrl){
	List *p,*s;
	if(i == 1){
		if(Ptrl != NULL){
			Ptrl = Ptrl->next;
			return Ptrl;
		}else{
			return NULL;
		}	

	}
	
	p = FindKth(i-1,Ptrl);
	
	if(p == NULL){
		printf("参数错了，找不到呢");
		return NULL;
	}else{
		s = p->next;
		p->next = s->next;
		free(s);
		
	}
		
	
} 

















