#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

//找到数组中第一个K的下标，如果数组中不存在K，则返回-1

int GetFirstK(int* data,int length,int k,int start,int end){
	if(start > end)
		return -1;
	
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	
	
	if(middleData == k){
		if((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
			return middleIndex;
		else
			end = middleIndex - 1;
	} else if(middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
	
	return GetFirstK(data.length,k,start.end);
	
}

//找到数组中最后一个K的下标。如果数组中不存在k,返回-1
int GetLastK(int* data,int length,int k,int start,int end){
	if(start > end)
		return -1;
	
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	
	if(middleData == k){
		if((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
			return middleIndex;
		else
			start = middleIndex + 1;
	} else if(middleData < k){
		start = middleIndex + 1;
	} else {
		end = middleIndex - 1;
	}
	
	
	return GetLastK(data,length,k,start,end);
	
}


int GetNumber(int* data,int length,int k){
	int number = 0;
	
	if(data != NULL && length > 0){
		int first = GetFirstK(data,length,k,0,length-1);
		int last = GetLastK(data,length,k,0,length-1);
		
		if(first > -1 && last > -1)
			number = last - first + 1;
		
	}
	
	return number;
	
}











