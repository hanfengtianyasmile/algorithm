#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node{
	int data;
	struct node *next;
}sqlist,*linklist;



//链表初始化 
linklist CreateLinkList(){
	linklist head = NULL;
	linklist s,r;
	int i;
	
	r = head;
	
	for(i = 1;i <= CardNumber;i++){
		s = (linklist)malloc(sizeof(sqlist));
		s->data = 0;
		
		if(head == NULL)
			head = s;
		else
			r->next = s;
			
		r = s;
		
	}
	
	r->next = head;
	
	return head;
	
} 



//链表销毁
 void DestroyList(linklist* list){
 	linklist ptr = *list;
 	linklist buff[CardNumber];
 	int i = 0;
 	
 	while(i < CardNumber){
 		buff[i++] = ptr;
 		ptr = ptr->next;
 	}
 	
 	for(i = 0;i < CardNumber;i++){
 		free(buff[i]);
 	}
 	
 	*list = 0;
 	
 	
 }

//发牌顺序计算
void Magcian(linklist head){
	linklist p;
	int j;
	int CountNumber = 2;
	
	p = head;
	p->data = 1;  //第一张牌放一
	
	while(1){
		for(j = 0;j < CountNumber; j++){
			p = p->next;
			if(p->data != 0){
				j--;
			}
		}
		
		if(p->data == 0){
			p->data = CountNumber;
			CountNumber++;
			
			if(CountNumber == 14)
				break;
			
		}	
	}
} 


int main(){
	
	linklist p;
	int i;
	
	p = CreateLinkList();
	
	Magcian(p);
	
	printf("按如下顺序排列:\n");
	
	for(i = 0;i < CardNumber; i++){
		printf("黑桃%d",p->data);
		p = p->next;
	}
	
	DestroyList(&p);
	
	return 0;
}























