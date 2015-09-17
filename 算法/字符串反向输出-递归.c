//字符串反向输出，以#作为结束
#include <stdio.h>
#include <stdlib.h>

void dump();

 void main(){
 		
	dump();
 }
 
 void dump(){
 	char a;
 	scanf("%c",&a);
	if( a != '#') dump();
	if( a != '#') printf("%c",a);
 }
