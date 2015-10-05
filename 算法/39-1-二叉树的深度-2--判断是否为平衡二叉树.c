#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

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


//判断是否为平衡二叉树
 bool IsBalanced(BinaryTreeNode* pRoot){
	 if(pRoot == NULL)
		 return true;
	 
	 int left = TreeDepth(pRoot->left);
	 int right = TreeDepth(pRoot->right);
	 int diff = left - right;
	 if(diff > 1 || diff < -1)
		 return false;
	 
	 return IsBalanced(pRoot->left) && IsBalanced(pRoot->right);
	 
	 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
