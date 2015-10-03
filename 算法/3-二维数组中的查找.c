#include <stdio.h>
#include <stdlib.h>




int Find(int (*arr)[4],int rows,int columns,int number){
	int row = 0;
	int column = columns -1;
	int found = 0;
	
	if(arr != NULL && rows > 0 && columns > 0){
		
		while(row < rows && column >= 0){
			if(*(*(arr+row)+column) == number){
				found = 1;
				break;
			}else if(*(*(arr+row)+column) > number){
				--column;
			}else{
				++row;
			}
		}
		
		
	}
	
	return found;
	
	
} 

int main(){
	int arr[4][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};
	printf("%d",Find(arr,4,4,100));
	return 0;
}







