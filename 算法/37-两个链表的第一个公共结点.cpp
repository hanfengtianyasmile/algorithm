#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};


unsigned int GetListLength(ListNode* pHead);

ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2){
	
	//得到两个链表的长度
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);
	int lengthDif = length1 - length2;
	
	ListNode* ListHeadLong = pHead1;
	ListNode* ListHeadShort = pHead2;
	
	if(length2 > length1){
		ListHeadLong = pHead2;
		ListHeadShort = pHead1;
		lengthDif = length2 - length1;
	}
	
	for(int i = 0;i < lengthDif;++i)
		ListHeadLong = ListHeadLong->m_pNext;
	
	while((ListHeadLong != NULL) && (ListHeadShort != NULL) && (ListHeadLong != ListHeadShort)){
		ListHeadLong = ListHeadLong->m_pNext;
		ListHeadShort = ListHeadShort->m_pNext;
	}
	
	//得到第一个公共结点
	ListNode* FirstCommonNode = ListHeadLong;
	
	return FirstCommonNode;
	
}


unsigned int GetListLength(ListNode* pHead){
	unsigned int length = 0;
	ListNode* pNode = pHead;
	
	while(pNode != NULL){
		++length;
		pNode = pNode->m_pNext;
	}
	
	return length;
}










