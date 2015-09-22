#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool g_InvalidInput = false;
bool equal(double num1,double num2);
double Power(double base,unsigned int exponent);


//º∆À„ 
double Math(double base,int exponent){
	unsigned int absExponent;
	
	g_InvalidInput = false;
	
	
	if(equal(base,0.0) && exponent < 0){
		g_InvalidInput = true;
		return 0.0;
	}
	
	if(exponent < 0)
		absExponent = (unsigned int)(-exponent);
	else
		absExponent = (unsigned int)(exponent);
		
	
	double result = Power(base,absExponent);
	
	if(exponent < 0)
		result = 1.0/result;
	
	
	return result;
	
}



double Power(double base,unsigned int exponent){
	
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;
	
	double result = Power(base,exponent >> 1);
	result *= result;
	
	//Œª‘ÀÀ„≈–∂œexponent∆Ê≈º
	if((exponent & 0x1) == 1)
		result *= base;
	
	return result; 
} 




bool equal(double num1,double num2){
	if((num1 - num2 > -0.0000001) && (num1 -num2 < 0.000001))
		return true;
	else
		return false;
}


int main(){
	double res = Math(2.00,4);
	printf("%e",res);
}

 
