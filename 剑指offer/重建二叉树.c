#include <stdio.h>
#include <stdlib.h>

//定义二叉树结构
typedef struct BiTreeNode{
	char data;
	struct BiTreeNode *left;
	struct BiTreeNode *right;
}BiTreeNode;

//函数
BiTreeNode * ConstructCore(int *preStart,int *preEnd,int *inStart,int *inEnd){
	
	//前序遍历的第一个元素为根节点
	int rootValue = preStart[0];
	
	//构建起始结点
	  
	BiTreeNode *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	root->data = rootValue;
	root->left = root->right = NULL;
	
	//遍历到最后一个元素
	if(preStart == preEnd){
		if(inStart == inEnd && *preStart == *inStart){
			return root;
		} else {
			printf("输入错误\n");
			return 0;
		}		
		
	} 
	
	//在中序遍历中找到根节点
	int *rootInorder = inStart;
	
	while(*rootInorder != rootValue && rootInorder < inEnd){
		rootInorder++;
	}
	
	
	//左字符串的地址偏移长度
	int leftLength = rootInorder - inStart; 
	//左字符串的前序遍历截止地址
	int *leftPreOrderEnd = preStart + leftLength;
	
	//开始构建递归
	if(leftLength > 0){
		//构建左子树 
		root->left =  ConstructCore(preStart + 1,leftPreOrderEnd,inStart,rootInorder-1);
	} 
	
	if(leftLength < preEnd - preStart){
		//构建右子树
		root->right =  ConstructCore(leftPreOrderEnd+1,preEnd,rootInorder+1,inEnd);
	}
	
	return root;
} 

//重建函数，输入前序遍历和中序遍历的首位置，长度
BiTreeNode * Construct(int *preOrder,int *inOrder,int length){
	//安全性检查
	if(preOrder == NULL || inOrder == NULL || length < 0){
		printf("错误输出\n");
		return 0;
	} 
	
	//开始进行核心组件的迭代
	return  ConstructCore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
	
} 


//打印后续遍历 
void LastOrder(BiTreeNode *root){
	if(root){
		LastOrder(root->left);
		LastOrder(root->right);
		printf("%d",root->data);
	}
}


int main(){
	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder[] = {4,7,2,1,5,3,8,6};
	int length = sizeof(preorder)/sizeof(int);
	BiTreeNode *t = Construct(preorder,inorder,length);
	printf("后序遍历结果为\n");
	LastOrder(t);
}





 
