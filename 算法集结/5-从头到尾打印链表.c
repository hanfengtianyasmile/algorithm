//��β��ͷ��ӡ����
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node{
	int data;
	struct Node *next;
}ListNode;


//�ݹ�ʵ�� 
void PrintListRever(ListNode * head){
	if(head != NULL){
		if(head->next != NULL){
			PrintListRever(head->next);
		}
		printf("%d",head->data);
	}
}

//����������ջ��Ч��ʵ�� 

