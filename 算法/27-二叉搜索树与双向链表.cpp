#include <stdio.h>

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList){
	
	if(pNode == NULL)
		return;
	
	BinaryTreeNode *pCurrent = pNode;
	
	if(pCurrent->left != NULL)
		convertNode(pCurrent->left,pLastNodeInList);
	
	pCurrent->left = *pLastNodeInList;
	
	if(*pLastNodeInList != NULL)
		(*pLastNodeInList)->right = pCurrent;
	
	*pLastNodeInList = pCurrent;
	
	if(pCurrent->right != NULL)
		convertNode(pCurrent->right,pLastNodeInList);
	
}


BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
	BinaryTreeNode *pLastNodeInList = NULL;
	ConvertNode(pRootOfTree,&pLastNodeInList);
	
	//需要返回头结点
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	
	while(pHeadOfList != NULL && pHeadOfList->left != NULL)
		pHeadOfList = pHeadOfList->left;
	
	return pHeadOfList;
	
}

















