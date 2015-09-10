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


//初始化线性表,返回指向线性表的指针 
List *Inits(){
	List *Ptrl;
	Ptrl = (List *)malloc( sizeof(List));
	Ptrl->Last = -1;
	return Ptrl;
} 


//查找 
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


//插入实现
void Insert(int x,int i,List *Ptrl){
	int j;
	if(Ptrl->Last == MAXSIZE){
		printf("表满了");
		return;
	}
	if(i < 1 || Ptrl->Last){
		printf("位置不合法");
		return;
	} 
	for(j = Ptrl->Last - 1;j >= i-1;j--)
		Ptrl->Data[j+1] = Ptrl->Data[j];
	Ptrl->Data[i-1] = x;
	Ptrl->Last++;
	return;
} 	

//删除操作
void Delete(int i,List *Ptrl){
	int j;
	if(i < 1 || i > Ptrl->Last)
		printf("不存在第%d个元素",i);
	for(j = i;j <= Ptrl->Last -1;j++)
		Ptrl->Data[j-1] = Ptrl->Data[j];
	Ptrl->Last--;
	return;
} 




















