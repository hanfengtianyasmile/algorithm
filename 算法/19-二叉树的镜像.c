#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
	int value;
	struct Node* left;
	struct Node* right;
}TreeNode; 



void MirrorRecursively(TreeNode* pNode){
	if(pNode == NULL)
		return;
	if(pNode->left == NULL && pNode->right)
		return;
		
	
	TreeNode* pTemp = pNode->left;
	pNode->left = pNode->right;
	pNode->right = pTemp;
	
	if(pNode->left)
		MirrorRecursively(pNode->left);
	
	
	if(pNode->right)
		MirrorRecursively(pNode->right);
	
} 


int main(){
	return 0;
}
 
