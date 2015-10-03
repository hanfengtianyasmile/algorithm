
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum,std::vector<int>& path,int& currentSum){
	
	currentSum += pRoot->value;
	path.push_back(pRoot->value);
	
	//�����Ҷ��㣬����·���ϵĽ��ĺ͵��������ֵ�����ӡ����·��
	bool isLeaf = pRoot->left == NULL && pRoot->right == NULL;
	
	if(currentSum == expectedSum && isLeaf){
		printf("һ��·�����ҵ����أ�");
		std::vector<int>::iterator iter = path.begin();
		for(;iter != path.end();++ iter){
			printf("%d\t",*iter);
		}
		printf("\n");
	}
	
	//�������Ҷ��㣬����������ӽ��
	if(pRoot->left != NULL)
		FindPath(pRoot->left,expectedSum,path,currentSum);
	
	if(pRoot->right != NULL)
		FindPath(pRoot->right,expectedSum,path,currentSum);
	
	//�ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ���
	path.pop_back();
	
}