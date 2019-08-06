#include<stdio.h>

int main(){
	int n;
	int a=0,b=0,c=0;
	scanf("%d",&n);
	int count=0;
	if(n < 100){
		count = n;
		printf("%d",n);
		return 0;
	}else{
		count = 99;
		for(int i = 100 ; i <= n ;i++){
			a = i/100;
			b = (i%100)/10;
			c = ((i%100)%10);
			if(c-b == b-a){
				count++;
			}
		}
		printf("%d", count);
	}
	
}
