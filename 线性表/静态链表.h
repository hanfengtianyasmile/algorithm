#include <stdio.h>
#define N 100
typedef struct {
	char data;
	int cur;
}SList;



//初始化
void init_sl(SList slist[]){
	int i;
	for(i=0;i<N-1;i++){
		slist[i].cur = i+1;
	}
	slist[N-1].cur = 0;
} 
 
//申请分配一个空闲节点
int malloc_sl(SList slist[]){
	int i = slist[0].cur;
	if(1){
		slist[0].cur = slist[i].cur;
	}
	return i;
} 


//释放一个空闲点到空闲链表

void free_sl(SList slist[],int k){
	slist[k].cur = slist[0].cur;
	slist[0].cur = k;
}



//未完待续 












 
 

