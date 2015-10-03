#include <stdio.h>
#include <stdlib.h>


char ReplaceBlank(char string[],int length){
	if(string == NULL || length <= 0){
		return 0;
	}
	
	//字符串的原始长度 
	int originalLength = 0;
	//字符串中空格个数
	int numberBlank = 0;
	
	int i =0;
	
	while(string[i] != '\0'){
		++ originalLength;
		if(string[i] == ' '){
			++ numberBlank; 
		}
		++ i;
	}
	
	//newLength为把空格替换成'%20'之后的长度 
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






