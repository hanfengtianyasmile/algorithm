//�ַ��������������#��Ϊ����
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
