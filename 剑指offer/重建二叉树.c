#include <stdio.h>
#include <stdlib.h>

//����������ṹ
typedef struct BiTreeNode{
	char data;
	struct BiTreeNode *left;
	struct BiTreeNode *right;
}BiTreeNode;

//����
BiTreeNode * ConstructCore(int *preStart,int *preEnd,int *inStart,int *inEnd){
	
	//ǰ������ĵ�һ��Ԫ��Ϊ���ڵ�
	int rootValue = preStart[0];
	
	//������ʼ���
	  
	BiTreeNode *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	root->data = rootValue;
	root->left = root->right = NULL;
	
	//���������һ��Ԫ��
	if(preStart == preEnd){
		if(inStart == inEnd && *preStart == *inStart){
			return root;
		} else {
			printf("�������\n");
			return 0;
		}		
		
	} 
	
	//������������ҵ����ڵ�
	int *rootInorder = inStart;
	
	while(*rootInorder != rootValue && rootInorder < inEnd){
		rootInorder++;
	}
	
	
	//���ַ����ĵ�ַƫ�Ƴ���
	int leftLength = rootInorder - inStart; 
	//���ַ�����ǰ�������ֹ��ַ
	int *leftPreOrderEnd = preStart + leftLength;
	
	//��ʼ�����ݹ�
	if(leftLength > 0){
		//���������� 
		root->left =  ConstructCore(preStart + 1,leftPreOrderEnd,inStart,rootInorder-1);
	} 
	
	if(leftLength < preEnd - preStart){
		//����������
		root->right =  ConstructCore(leftPreOrderEnd+1,preEnd,rootInorder+1,inEnd);
	}
	
	return root;
} 

//�ؽ�����������ǰ������������������λ�ã�����
BiTreeNode * Construct(int *preOrder,int *inOrder,int length){
	//��ȫ�Լ��
	if(preOrder == NULL || inOrder == NULL || length < 0){
		printf("�������\n");
		return 0;
	} 
	
	//��ʼ���к�������ĵ���
	return  ConstructCore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
	
} 


//��ӡ�������� 
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
	printf("����������Ϊ\n");
	LastOrder(t);
}





 
