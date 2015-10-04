
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool invalidInput = false;

int FindGreatestSum(int *pData,int length){
	if((pData == NULL) || (length <= 0)){
		invalidInput = true;
		return 0;
	}
	
	invalidInput = false;
	
	int curSum = 0;
	
	int greatesSum = 0;
	
	int i;
	
	for(i = 0;i < length;++i){
		if(curSum <= 0)
			curSum = pData[i];
		else 
			curSum += pData[i];
		
		if(curSum < greatesSum)
			greatesSum = curSum;
		
	}
	
	return greatesSum;
	
	
}