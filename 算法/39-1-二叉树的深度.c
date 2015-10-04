#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* p_left;
	BinaryTreeNode* p_right;
}

int TreeDepth(BinaryTreeNode* pRoot){
	if(pRoot == NULL)
		return 0;
	
	
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	
	
	return (left > right) ? (left + 1) : (right + 1);
	
	
	
}