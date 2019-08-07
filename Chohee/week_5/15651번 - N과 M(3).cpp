#include<iostream>
#include<vector> 
#include<stdio.h>
using namespace std;

vector<int> Arr;
vector<int> Select;
void PwithRepetition(int n, int r, int count);

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; i++){
		Arr.push_back(i+1);
		Select.push_back(0);
	}
	PwithRepetition(N, M, 0);
}

/* 중복순열 구하는 알고리즘 */ 
void PwithRepetition(int n, int r, int count){
	if(count == r){
		for(int i = 0 ; i < r ; i++){
			cout<<Select[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(int i = 0 ; i < n ; i++){
		Select[count] = Arr[i];
		PwithRepetition(n, r, count+1);
	}
}
