#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	// 자연수 N 입력. 
	long long N;
	scanf("%lld", &N);

	string binaryResult; // string 자료형 출력변수.
	long long Q = N;
	char R = 0; // Q = 몫, R = 나머지.
	while(Q > 1){
		N = Q;
		R = N%2 + 48;
		Q = N/2;
		binaryResult.insert(0, 1, R);
	} 
	binaryResult.insert(0,1,49);
	cout<<binaryResult;
}
