struct ComplexListNode
{
    int                 m_nValue;
    ComplexListNode*    m_pNext;
    ComplexListNode*    m_pSibling;
};

ComplexListNode* CreateNode(int nValue);
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
void PrintList(ComplexListNode* pHead);


ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();
    
    pNode->m_nValue = nValue;
    pNode->m_pNext = NULL;
    pNode->m_pSibling = NULL;

    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != NULL)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);

        if(pNode->m_pSibling != NULL)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}


void CloneNodes(ComplexListNode* pHead);

void ConnectSiblingNodes(ComplexListNode* pHead);

ComplexListNode* ReconnectNodes(ComplexListNode* pHead);


void CloneNodes(ComplexListNode* pHead){
	
	ComplexListNode* pNode = pHead;
	
	while(pNode != NULL){
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;
		
		pNode->m_pNext = pCloned;
		
		pNode = pCloned->m_pNext;
	
	}	
	
}

void ConnectSiblingNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	while(pNode != NULL){
		ComplexListNode* pCloned = pNode->m_pNext;
		if(pNode->m_pSibling != NULL){
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}



ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;
	
	if(pNode != NULL){
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	
	while(pNode != NULL){
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		
		pNode->m_pNext = pCloned->m_pNext;
		pNode = pNode->m_pNext;
		
	}
	
	return pClonedHead;
	
	
	
}


















