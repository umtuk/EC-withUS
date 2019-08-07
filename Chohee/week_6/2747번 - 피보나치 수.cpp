#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int data[46] = {0};
	data[0] = 0, data[1] = 1;
	for(int i = 2 ; i <= 45 ; i++){
		data[i] = data[i-1] + data[i-2];
	}
	printf("%d", data[n]);
}
