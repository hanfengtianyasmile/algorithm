#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
	int value;
	struct Node* left;
	struct Node* right;
}TreeNode; 


bool DoesTree1HaveTree2(TreeNode* root1,TreeNode* root2){
	if(root2 == NULL){
		return true;
	}
	if(root1 == NULL){
		return false;
	}
	
	if(root1->value != root2->value){
		return false;
	}
	
	return DoesTree1HaveTree2(root1->left,root2->left) && DoesTree1HaveTree2(root1->right,root2->right);
	
	
}

bool HasSubTree(TreeNode* root1,TreeNode* root2){
	bool result = false;
	if(root1 != NULL && root2 != NULL){
		if(root1->value == root2->value){
			result = DoesTree1HaveTree2(root1,root2);
		}
		if(!result){
			result = HasSubTree(root1->left,root2);
		}
		if(!result){
			result = HasSubTree(root1->right,root2);
		}		
	}
	return result;
}

int main(){
	return 0;
}











 
