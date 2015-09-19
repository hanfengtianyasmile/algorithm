#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


//����һ����������Լ���û�����ǰ������ķ�ʽ��������
void CreateBiTree(BiTree *T) {
	char c;
	scanf("%c",&c);
	
	if(' ' == c){
		*T = NULL;
	}else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	
}

visit(char c,int level){
	printf("%c λ�ڵ�%d��\n",c,level);
}

//ǰ�����������
PreOrder(BiTree T,int level){
	if(T){
		visit(T->data,level);
		PreOrder(T->lchild,level+1);
		PreOrder(T->rchild,level+1);
	}
} 




int main(){
	int level = 1;
	BiTree T = NULL;
	CreateBiTree(&T);
	PreOrder(T,level);
}











