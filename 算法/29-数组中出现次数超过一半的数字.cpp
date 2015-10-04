#include <stdio.h>
#include <stdbool.h>

bool inputInvalid = false;

bool CheckInvalidArray(int* numbers,int length){
	inputInvalid = false;
	if(numbers == NULL && length <= 0)
		inputInvalid = true;
	
	return inputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number){
	int times = 0;
	for(int i = 0; i < length;++i){
		if(number[i] == number)
			times++;
	}
	
	bool isMoreThanHalf = true;
	
	if(times * 2 <= length){
		isMoreThanHalf = false;
	}
	
	return isMoreThanHalf;
}

int MoreThanHalfNum(int *numbers,int length){
	if(CheckInvalidArray(numbers,length))
		return 0;
	
	int result = numbers[0];
	int times = 1;
	
	for(int i = 1;i < length; ++i){
		if(times == 0){
			result = numbers[i];
			times = 1;
		} else if(numbers[i] == result){
			times++;
		} else {
			times--;
		}
	}
	
	if(!CheckMoreThanHalf(numbers,length,result))
		result = 0;
	
	return result;
	
	
	
}




