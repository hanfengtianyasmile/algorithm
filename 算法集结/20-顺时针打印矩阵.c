#include <stdlib.h>
#include <stdio.h>

void printNumber(int number){
	printf("%d",number);
}

void PrintCircle(int** numbers,int columns,int rows,int start){
	int endX = columns -1 - start;
	int endY = rows -1 - start;
	int i;
	
	//�����Ҵ�ӡһ��
	for(i = start;i <= endY; ++i){
		int number = numbers[start][i];
		printNumber(number);
	} 
	
	//���ϵ��´�ӡһ��
	if(start < endY){
		for(i = start +1;i <= endY;++i){
			int number = numbers[i][endX];
			printNumber(number);
		}
	} 
	
	//���ҵ����ӡһ��
	if(start < endX && start < endY){
		for(i = endX -1;i >= start; --i){
			int number = numbers[endY][i];
			printNumber(number);
		}
	} 
	
	//���ϵ��´�ӡһ��
	if(start < endX && start < endY -1){
		for(i = endY - 1;i >= start + 1;--i){
			int number = numbers[i][start];
			printNumber(number);
		}
	} 
	
	
	
}

void PrintClock(int** numbers,int columns,int rows){
	
	if(numbers == NULL || columns <= 0 || rows <= 0)
		return;
		
	int start = 0;
	
	while(columns > start * 2 && rows > start * 2){
		PrintCircle(numbers,columns,rows,start);
	}
	
} 



int main(){
	return 0;
}




 
