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
		int input;
		scanf("%d", &input);
		Arr.push_back(input);
		Select.push_back(0);
	}
	// 버블정렬 
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N-1 ; j++){
			if(Arr[j] > Arr[j+1]){
				int tmp = Arr[j+1];
				Arr[j+1] = Arr[j];
				Arr[j] = tmp;
			}
		}
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
