//从尾到头打印链表
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node{
	int data;
	struct Node *next;
}ListNode;


//递归实现 
void PrintListRever(ListNode * head){
	if(head != NULL){
		if(head->next != NULL){
			PrintListRever(head->next);
		}
		printf("%d",head->data);
	}
}

//还可以利用栈的效果实现 

