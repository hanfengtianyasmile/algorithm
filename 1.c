#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10 



typedef struct{
	int Data[MAXSIZE];
	int Last;
}List;

List L,*Ptrl;

int main(void){
	
}


//��ʼ�����Ա�,����ָ�����Ա��ָ�� 
List *Inits(){
	List *Ptrl;
	Ptrl = (List *)malloc( sizeof(List));
	Ptrl->Last = -1;
	return Ptrl;
} 


//���� 
int Find(int x,List * Ptrl){
	int i = 1;
	while(i <= Ptrl->Last && Ptrl->Data[i] != x)
		i++;
	if(i > Ptrl->Last){
		return -1;
	}else{
		return i;
	}	
} 


//����ʵ��
void Insert(int x,int i,List *Ptrl){
	int j;
	if(Ptrl->Last == MAXSIZE){
		printf("������");
		return;
	}
	if(i < 1 || Ptrl->Last){
		printf("λ�ò��Ϸ�");
		return;
	} 
	for(j = Ptrl->Last - 1;j >= i-1;j--)
		Ptrl->Data[j+1] = Ptrl->Data[j];
	Ptrl->Data[i-1] = x;
	Ptrl->Last++;
	return;
} 	

//ɾ������
void Delete(int i,List *Ptrl){
	int j;
	if(i < 1 || i > Ptrl->Last)
		printf("�����ڵ�%d��Ԫ��",i);
	for(j = i;j <= Ptrl->Last -1;j++)
		Ptrl->Data[j-1] = Ptrl->Data[j];
	Ptrl->Last--;
	return;
} 




















