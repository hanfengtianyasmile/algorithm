#include  <stdio.h>
#define ListSize 100
typedef int DataType;
typedef struct{
	DataType list[ListSize];
	int length;
}SeqList;

//��ʼ�����Ա�
 void InitList(SeqList *L){
 	L->length = 0; 
 } 
 
 
 //�ж����Ա��Ƿ�Ϊ��
 int ListEmpty(SeqList L){
 	if(L.length == 0){
 		return 1;
 	}else{
 		return 0;
 	}
 } 
 
 
 //����Ų���
 int GetElem(SeqList L,int i,DataType *e){
 	if(i < 1 || i>L.length)
 		return -1;
 	* e = L.list[i-1];
 	return 1;
 } 
 
 //�����ݲ���
int LocateElem(SeqList L,DataType e){
	int i;
	for(i = 0;i<L.length;i++)
		if(L.list[i] == e)
			return i+1;
	return 0;
} 

//����Ԫ�� 
int InsertList(SeqList *L,int i,DataType e){
	int j;
	if(i < 1 || i > length + 1){
		printf("����λ�ò��Ϸ�\n");
		return -1;
	}else if(L->length >= ListSize){
		printf("˳����Ѿ����ˣ����ܲ���Ԫ��\n");
		return 0;
	} else {
		for(j = L->length;j >= i;j--)
			L->list[j] = L->list[j-1];
		L->list[i-1] = e;
		L->length = L->length + 1;
		return 1;
	}
	
}

//ɾ��Ԫ��
int DeleteList(SeqList *L,int i,DataType *e){
	int j;
	if(L->length <= 0){
		printf("˳����ѿղ���ɾ��\n");
		return 0;
	}else if(1 < 1 || i > L->length){
		printf("ɾ��λ�ò�����\n");
		return -1;
	}else{
		*e = L->list[i-1];
		for(j = i;j <= L->length-1;j++)
			L->list[i-1] = L->list[i];
		L->length = L->length - 1;
		return 1;
	}
} 

int main(){
	
}


 
 




