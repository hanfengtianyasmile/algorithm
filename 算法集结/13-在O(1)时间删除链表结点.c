#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int value;
	struct ListNode * pNext;
}ListNode; 

void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted){
	if(!pListHead || !pToBeDeleted)
		return;
	
	//Ҫɾ���Ľ�㲻��β���
	if(pToBeDeleted->pNext != NULL){
		ListNode* pNext = pToBeDeleted->pNext;
		pToBeDeleted->value = pNext->value;
		pToBeDeleted->pNext = pNext->pNext;
		
		free(pNext);
		pNext = NULL;
	} else if(*pListHead == pToBeDeleted){
		//����ֻ��һ����㣬ɾ��ͷ���
		free(pToBeDeleted);
		pToBeDeleted = NULL;
		*pListHead = NULL;
	} else{
		//�������ж����㣬ɾ��β���
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










