
//循环加递归

#include <stdio.h>


void Permutate(char *str){
	if(str == NULL)
		return;
	Permutation(str,str);
}


void Permutation(char* str,char* begin){
	if(*begin == '\0'){
		printf("%s\n",str);
	} else {
		for(char* ch = begin;*ch != '\0';++ch){
			char temp = *ch;
			*ch = *begin;
			*begin = temp;
			
			Permutation(str,begin+1);
			
			temp = *ch;
			*ch = *begin;
			*begin = temp;
			
		}
	}

}










