#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int value;
	struct Node* next;
}ListNode; 


ListNode* FindToTail(ListNode* pListHead,int k){
	
	if(pListHead == NULL || k == 0){
		return NULL;
	}
	
	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;
	
	int i;
	
	for(i = 0;i < k -1;i++){
		if(pAhead->next != NULL){
			pAhead = pAhead->next;	
		}	
		else {
			return NULL;
		}
	}
	
	pBehind = pListHead;
	
	while(pAhead->next != NULL){
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	
	return pBehind;
	
	
}






int main(){
	return 0;
}

