#include <stdio.h>
#include <stdlib.h>


char ReplaceBlank(char string[],int length){
	if(string == NULL || length <= 0){
		return 0;
	}
	
	//�ַ�����ԭʼ���� 
	int originalLength = 0;
	//�ַ����пո����
	int numberBlank = 0;
	
	int i =0;
	
	while(string[i] != '\0'){
		++ originalLength;
		if(string[i] == ' '){
			++ numberBlank; 
		}
		++ i;
	}
	
	//newLengthΪ�ѿո��滻��'%20'֮��ĳ��� 
	int newLength = originalLength + numberBlank * 2;
	
	if(newLength > length){
		return 0;
	}
	
	
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
		if(string[indexOfOriginal] == ' '){
			string[indexOfNew --] = '0';
			string[indexOfNew --] = '2';
			string[indexOfNew --] = '%';
		} else {
			string[indexOfNew --] = string[indexOfOriginal];
		}
		-- indexOfOriginal;
	}
	
	printf("%s",string);
	return 	0;
	
} 

int main(){
	char string[] = "li jun  giuang";
	ReplaceBlank(string,100);
	
	return 0;
}






