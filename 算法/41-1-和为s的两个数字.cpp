#include <stdio.h>
#include <stdlib.h>



bool FindNumberWithSum(int data[],int length,int sum,int* num1,int* num2){
	
	bool found = false;
	if(length < 1 || num1 == NULL || num2 == NULL)
		return found;
	
	while(ahead > behind){
		
		long long curSum = data[ahead] + data[behind];
		
		if(curSum == sum){
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		} else if (curSum > sum){
			ahead --;
		} else {
			behind ++;
		}
	}
	
	return found;
	
}















