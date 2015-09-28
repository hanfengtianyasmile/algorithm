#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
}ListNode; 

ListNode* ReverseList(ListNode* pHead){
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	
	while(pNode != NULL){
		ListNode* pNext = pNode->next;
		if(pNext == NULL)
			pReverseHead = pNode;
		
		pNode->next = pPrev;
		
		pPrev = pNode;
		pNode = pNext;
				
	}
	
	return pReverseHead;
	
} 

int main(){
	return 0;
}














