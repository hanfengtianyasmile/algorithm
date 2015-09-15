#include <stdio.h>
#include <stdlib.h>


typedef struct CLinkList{
	int data;
	struct CLinkList *next;
}node;



//��ʼ��ѭ������
void ds_init(node **pNode){
	int item;
	node *temp;
	node *target;
	
	printf("�������ֵ������0��ɳ�ʼ��\n");
	
	while(1){
		scanf("%d",&item);
		fflush(stdin);
		
		if(item == 0)
			return;
			
		if((*pNode) == NULL){
			*pNode = (node *)malloc(sizeof(struct CLinkList));
			if(!(*pNode))
				exit(0);
				
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		} else {
			/*�ҵ�nextָ���һ�����Ľ��*/
			for(target = (*pNode);target->next != (*pNode);target = target->next);
			
			/*����һ���µĽ��*/
			temp = (node *)malloc(sizeof(struct CLinkList));
			
			if(!temp)
				exit(0);
				
			temp->data = item;
			
			temp->next = *pNode;
			
			target->next = temp;
			 
		}
		
		
		
	}
	
}


//������
void ds_insert(node **pNode,int i){
	node *temp;
	node *target;
	node *p;
	int item;
	int j = 1;
	
	
	printf("����Ҫ�������ֵ:");
	scanf("%d",&item);
	
	if(i == 1){
		//�²���Ľ����Ϊ��һ�����
		temp = (node *)malloc(sizeof(struct CLinkList));
		
		if(!temp)
			exit(0);
			
		temp->data = item;
		
		/*Ѱ�ҵ����һ�����*/
		
		for(target = (*pNode);target->next != (*pNode);target = target->next);
		
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
		
		 
	} else {
		target = *pNode;
		for(j = 1;j < (i-1);j++){
			target = target->next;
		}
		
		temp = (node *)malloc(sizeof (struct CLinkList));
		
		if(!temp)
			exit(0);
			
		temp->data = item;
		
		p = target->next;
		
		target->next = temp;
		
		temp->next = p;
		
		
	}
	
	
}


//ɾ�����
void ds_delete(node **pNode,int i){
	node *target;
	node *temp;
	int j = 1;
	
	
	if(i == 1){
		//ɾ�����ǵ�һ�����
		for(target = *pNode;target->next != *pNode;target = target->next);
		
		temp = *pNode;
		*pNode = (*pNode)->next;
		target->next = *pNode;
		free(temp);
		 
	} else {
		
		target = *pNode;
		for(j = 1;j < i-1;j++){
			target = target->next;
		} 
		
		temp = target->next;
		target->next = temp->next;
		free(temp);
	
		
	}
	
}


//���ؽ���λ��
int ds_search(node *pNode,int elem){
	node *target;
	int i = 1;
	
	for(target = pNode;target->data != elem && target->next != pNode;i++){
		target = target->next;
	}
	
	if(target->next == pNode)
		return 0;
	else
		return i;
	
} 



int main(){
	return 1;
} 

















