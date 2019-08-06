#include<stdio.h>

int main(){
	int R, B;
	scanf("%d %d", &R, &B);
	for(int i = 1 ; i <= B ; i++){
		if(B%i == 0){
			int checkR = i*2 + (B/i)*2 + 4;
			if(checkR == R && (B/i)+2 >= i+2){
				printf("%d %d", (B/i)+2, i+2);
			}	
		}
	}
}
