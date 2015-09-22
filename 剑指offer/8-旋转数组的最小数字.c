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
 		
 		//���index1��index2���ڣ�
		//��ôindex1ָ���һ��������������һ�����֣�
		//index2ָ��ڶ�����������ĵ�һ������ ��Ҳ������С������ 
 		
 		if(index2 - index1 == 1){
 			indexMid = index2;
 			break;
 		}
 		
 		//����±�Ϊindex1��index2��indexMidָ��������������
		//ֻ��˳�����
		
		indexMid = (index1 + index2) / 2;
		
		//����±�Ϊindex1��index2��indexMidָ��������������
		//����˳����� 
		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1]){
			return MinInOrder(numbers,index1,index2);
		}
		
		//���ַ�����С���ҷ�Χ
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



