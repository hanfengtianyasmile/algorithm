#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
}ListNode; 

ListNode* Merge(ListNode* pHead1,ListNode* pHead2){
	
	if(pHead1 == NULL){
		return pHead2;
	}else if(pHead2 == NULL){
		return pHead1;
	}
	
	ListNode* pMergedHead = NULL;
	
	if(pHead1->value < pHead2->value){
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next,pHead2);
	} else {
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1,pHead2->next);
	}
	
	return pMergedHead;
	
	
} 


int main(){
	return 0;
}





