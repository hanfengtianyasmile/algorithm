#include <stdio.h>
#define N 100
typedef struct {
	char data;
	int cur;
}SList;



//��ʼ��
void init_sl(SList slist[]){
	int i;
	for(i=0;i<N-1;i++){
		slist[i].cur = i+1;
	}
	slist[N-1].cur = 0;
} 
 
//�������һ�����нڵ�
int malloc_sl(SList slist[]){
	int i = slist[0].cur;
	if(1){
		slist[0].cur = slist[i].cur;
	}
	return i;
} 


//�ͷ�һ�����е㵽��������

void free_sl(SList slist[],int k){
	slist[k].cur = slist[0].cur;
	slist[0].cur = k;
}



//δ����� 












 
 

