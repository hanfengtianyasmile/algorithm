
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum,std::vector<int>& path,int& currentSum){
	
	currentSum += pRoot->value;
	path.push_back(pRoot->value);
	
	//如果是叶结点，并且路径上的结点的和等于输入的值，则打印这条路径
	bool isLeaf = pRoot->left == NULL && pRoot->right == NULL;
	
	if(currentSum == expectedSum && isLeaf){
		printf("一个路径被找到了呢：");
		std::vector<int>::iterator iter = path.begin();
		for(;iter != path.end();++ iter){
			printf("%d\t",*iter);
		}
		printf("\n");
	}
	
	//如果不是叶结点，则遍历它的子结点
	if(pRoot->left != NULL)
		FindPath(pRoot->left,expectedSum,path,currentSum);
	
	if(pRoot->right != NULL)
		FindPath(pRoot->right,expectedSum,path,currentSum);
	
	//在返回父节点之前，在路径上删除当前结点
	path.pop_back();
	
}