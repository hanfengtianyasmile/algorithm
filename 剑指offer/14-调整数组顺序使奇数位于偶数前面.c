#include <stdio.h>
#include <stdlib.h>


void ReorderOddEven(int *pData,int length){
	if(pData == NULL || length == 0)
		return;
	
	int *pBegin = pData;
	int *pEnd = pData + length -1;
	
	while(pBegin < pEnd){
		//向后移动pBegin,直到它指向偶数
		while(pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;
		
		//向前移动pEnd,直到它指向奇数
		while(pBegin < pEnd && (*pEnd & 0x1) == 0)
			pEnd--;
			
		
		if(pBegin < pEnd){
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		} 	
	}
	
} 

void main(){
	int i;
	int numbers[] = {1,2,3,4,5,6,7,8};
	int length = sizeof(numbers)/sizeof(int);
	ReorderOddEven(numbers,length);
	for(i = 0;i < length;++i){
		printf("%d",numbers[i]);
	}
}








 
