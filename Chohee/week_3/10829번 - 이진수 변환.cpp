#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	// �ڿ��� N �Է�. 
	long long N;
	scanf("%lld", &N);

	string binaryResult; // string �ڷ��� ��º���.
	long long Q = N;
	char R = 0; // Q = ��, R = ������.
	while(Q > 1){
		N = Q;
		R = N%2 + 48;
		Q = N/2;
		binaryResult.insert(0, 1, R);
	} 
	binaryResult.insert(0,1,49);
	cout<<binaryResult;
}
