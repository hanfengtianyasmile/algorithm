#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


//创建一个二叉树，约定用户按照前序遍历的方式输入数据
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
	printf("%c 位于第%d层\n",c,level);
}

//前序遍历二叉树
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











