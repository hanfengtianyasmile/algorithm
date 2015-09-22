#include <stdio.h>
#include <stdlib.h>

int MinInOrder(int * numbers,int index1,int index2);


 int Min(int * numbers,int length){
 	if(numbers == NULL || length <= 0)
 		return 0;
 	
 	int index1 = 0;
 	int index2 = length - 1;
 	int indexMid = index1;
 	
 	while(numbers[index1] >= numbers[index2]){
 		
 		//如果index1与index2相邻，
		//那么index1指向第一个递增数组的最后一个数字，
		//index2指向第二个递增数组的第一个数字 ，也就是最小的数字 
 		
 		if(index2 - index1 == 1){
 			indexMid = index2;
 			break;
 		}
 		
 		//如果下标为index1、index2和indexMid指向的三个数字相等
		//只能顺序查找
		
		indexMid = (index1 + index2) / 2;
		
		//如果下标为index1、index2和indexMid指向的三个数字相等
		//按照顺序查找 
		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1]){
			return MinInOrder(numbers,index1,index2);
		}
		
		//二分法，缩小查找范围
		if(numbers[indexMid] >= numbers[index1]){
			index1 = indexMid;
		} else if(numbers[indexMid] <= numbers[index2]){
			index2 = indexMid;
		}

 		
 	}
 	
 	
 	
 	return numbers[indexMid];
 		
 	
 }


int MinInOrder(int * numbers,int index1,int index2){
	int result = numbers[index1];
	int i;
	for(i = index1 + 1;i <= index2; ++i){
		if(result > numbers[i])
			result = numbers[i];
	}
	return result;
}

int main(){
	int arr[] = {3,4,5,1,2};
	int res = Min(arr,sizeof(arr)/sizeof(int));
	printf("%d",res);
	return 0;
}



