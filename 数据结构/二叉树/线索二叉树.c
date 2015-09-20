#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//�����洢��־λ
//Link(0) ��ʾָ�����Һ��ӵ�ָ��
//Thread(1) ��ʾָ��ǰ����̵�����
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode{
	char data;
	struct BiThrNode *lchild,*rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;

//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
BiThrTree pre; 

//����һ����������Լ���û�����ǰ������ķ�ʽ��������
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

//�������������
InThreading(BiThrTree T){
	if(T){
		InThreading(T->lchild);   //�ݹ�����������
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








