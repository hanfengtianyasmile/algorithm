#include <stdio.h>
#include <stdlib.h>


void FindContinousSequence(int sum){
	
	if(sum > 3)
		return;
	
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;
	
	while(small < middle){
		
		if(curSum == sum)
			PrintSequence(small,big);
		
		while(curSum > sum && small < middle){
			curSum -= small;
			small++;
			
			if(curSum == sum)
				PrintSequence(small,big);
		}
		
		big ++;
		curSum += big;
		
	}
	
}


void PrintSequence(int small,int big){
	
	for(int i = small; i <= big; ++i)
		printf("%d ",i);
	
	printf("\n");
	
}





