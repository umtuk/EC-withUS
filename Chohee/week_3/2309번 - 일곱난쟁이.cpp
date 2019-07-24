#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int ninePeople[9] = {0};
	int sum = 0;
	for(int i = 0 ; i < 9 ; i++){
		cin>>ninePeople[i];
		sum += ninePeople[i];
	}
	//완전탐색 
	int pivotLeft = 0, pivotRight = 1;
	int pickLeft = 0, pickRight = 0;
	bool check = false;
	while(pivotLeft < 8 && pivotRight < 9){
		for(int i = pivotRight ; i < 9 ; i++){
			int sevenSum = sum - (ninePeople[pivotLeft] + ninePeople[i]);
			if(sevenSum == 100){
				pickLeft = pivotLeft;
				pickRight = i;
				check = true;
			} 
		}
		if(check != true){
			pivotLeft++;
			pivotRight++;
		}else{
			ninePeople[pickLeft] = 0;
			ninePeople[pickRight] = 0;
			break;
		} 
	} 
	//정렬(버블소트)
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(ninePeople[j]>ninePeople[j+1]){
				int tmp = ninePeople[j];
				ninePeople[j] = ninePeople[j+1];
				ninePeople[j+1] = tmp;
			}
		}
	}
	for(int i = 0 ; i < 9 ; i++){
		if(ninePeople[i] != 0){
			printf("%d\n", ninePeople[i]);
		}
	} 
	 
}
