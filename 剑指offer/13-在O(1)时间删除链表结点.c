#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int value;
	struct ListNode * pNext;
}ListNode; 

void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted){
	if(!pListHead || !pToBeDeleted)
		return;
	
	//要删除的结点不是尾结点
	if(pToBeDeleted->pNext != NULL){
		ListNode* pNext = pToBeDeleted->pNext;
		pToBeDeleted->value = pNext->value;
		pToBeDeleted->pNext = pNext->pNext;
		
		free(pNext);
		pNext = NULL;
	} else if(*pListHead == pToBeDeleted){
		//链表只有一个结点，删除头结点
		free(pToBeDeleted);
		pToBeDeleted = NULL;
		*pListHead = NULL;
	} else{
		//链表中有多个结点，删除尾结点
		 ListNode * pNode = *pListHead;
		 while(pNode->pNext != pToBeDeleted){
		 	pNode = pNode->pNext;
		 }
		 
		 pNode->pNext = NULL;
		 
		 free(pToBeDeleted);
		 
		 pToBeDeleted = NULL;
		 
		 
		 
	}
	
	
	
	 
	
	
	
	
}

int main(){
	
	return 0;
}










