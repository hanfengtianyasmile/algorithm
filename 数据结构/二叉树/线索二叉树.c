#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位
//Link(0) 表示指向左右孩子的指针
//Thread(1) 表示指向前驱后继的线索
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode{
	char data;
	struct BiThrNode *lchild,*rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;

//全局变量，始终指向刚刚访问过的结点
BiThrTree pre; 

//创建一个二叉树，约定用户遵照前序遍历的方式输入数据
CreateBiThrTree(BiThrTree *T){
	char c;
	scanf("%c",&c);
	
	if(' ' == c){
		*T = NULL;
	} else {
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}		
} 

//中序遍历线索化
InThreading(BiThrTree T){
	if(T){
		InThreading(T->lchild);   //递归左孩子线索化
		if( !T->lchild ){
			T->ltag = Thread;
			T->lchild = pre;
		} 
		if( !pre->rchild ){
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
} 

InOrderThreading(BiThrTree *p,BiThrTree T){
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if(!T){
		(*p)->lchild = *p;
	} else {
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);	
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}


int main(){
	
	BiThrTree p,T = NULL;
	
	CreateBiThrTree(&T);
	
	InOrderThreading(&p,T);
	
	return 0;
}








