#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef int ElemType;


typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode , *QueuePtr;

typedef struct {
	QueuePtr front,rear;
}LinkQueue;

//创建一个队列 
initQueue(LinkQueue *q){
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!q->front)
		exit(0);
	q->front->next = NULL;
}


//队列插入
InsertQueue(LinkQueue *q,ElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	
	if(p == NULL)
		exit(0);
		
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	
} 


//出队列操作
DeleteQueue(LinkQueue *q,ElemType *e){
	QueuePtr p;
	if(q->front == q->rear)
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if(q->rear == p)
		q->rear = q->front;
	free(p);
} 

//销毁一个队列
DestroyQueue(LinkQueue *q){
	while(q->front){
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
} 

int main(){
	return 0;
}














