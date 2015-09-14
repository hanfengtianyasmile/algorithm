#include <stdio.h>
#define N 100
typedef struct {
	char data;
	int cur;
}SList;

typedef struct{
	SList list[N];
}SLinkList;

//��ʼ��
void init_sl(SLinkList *L){
	int i;
	for(i=0;i<N-1;i++){
		L->list[i].cur = i+1;
	}
	L->list[N-1].cur = 0;
} 
 
//�������һ�����нڵ�
int malloc_sl(SLinkList *L){
	int i = L->list[0].cur;
	if(1){
		L->list[0].cur = L->list[i].cur;
	}
	return i;
} 


//�ͷ�һ�����е㵽��������

void free_sl(SLinkList *L,int k){
	L->list[k].cur = L->list[0].cur;
	L->list[0].cur = k;
}



//�ڵ�i��Ԫ��֮ǰ�����µ�����Ԫ��e
int ListInsert(SLinkList *L,int i,char e){
	int j,k,l;
	k = N -1;
	if(i < 1 || i > N){
		return 0;
	}
	
	j = malloc_sl(L);
	
	if(j){
		L->list[j].data = e;
		for(l = 1;l <= i-1;l++){
			k = L->list[k].cur;
		}
		
		L->list[j].cur = L->list[k].cur;
		L->list[k].cur = j;
		
		return 1;
		
	}
	
	return 0;
	
} 

//ɾ����L�еĵ�i��Ԫ��
int ListDelete(SLinkList *L,int i){
	int j,k;
	if(i < 1 || i > N){
		return 0;
	}
	
	k = N - 1;
	
	for(j = 1;j <= i-1; j++){
		k = L->list[k].cur;
	}
	j = L->list[k].cur;
	
	L->list[k].cur = L->list[j].cur;
	
	free_sl(L,j);
	
	return 1;
	
	
} 











 
 

