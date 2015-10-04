#include <stdio.h>
#include <tchar.h>

int Min(int number1,int number2,int number3);

int GetUglyNumber(int index){
	
	if(index <= 0)
		return 0;
	
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	
	int *pUgly2 = pUglyNumbers;
	int *pUgly3 = pUglyNumbers;
	int *pUgly5 = pUglyNumbers;
	
	
	while(nextUglyIndex < index){
		int min = Min(*pUgly2 * 2,*pUgly3 * 3,*pUgly5 * 5);
		pUglyNumbers[nextUglyIndex] = min;
		
		while(*pUgly2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pUgly2;
		
		while(*pUgly3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pUgly3;
		
		while(*pUgly5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pUgly5;
		
		++nextUglyIndex;
	}
	
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
	
	
}

int Min(int number1,int number2,int number3){
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	
	return min;
}





