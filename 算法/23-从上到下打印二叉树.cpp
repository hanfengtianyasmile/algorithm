struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
	if(!pTreeRoot)
			return;
	std::deque<BinaryTreeNode *> dequeTreeNode;
	
	dequeTreeNode.push_back(pTreeRoot);
	
	while(dequeTreeNode.size()){
		
		BinaryTreeNode *pNode = dequeTreeNode.front();
		BinaryTreeNode.pop_front();
		
		printf("%d",pNode->value);
		
		if(pNode->left){
			dequeTreeNode.push_back(pNode->left);
		}
		
		if(pNode->right){
			dequeTreeNode.push_back(pNode->right);
		}
		
		
	}
	
}