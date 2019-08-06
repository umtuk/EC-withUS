#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> Arr;
vector<bool> Select;
void Combination(int N, int M, int start, int count);

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 1 ; i <= N ; i++){
		Arr.push_back(i);
		Select.push_back(0);
	}
	Combination(N, M, 0, 0);
	
}

void Combination(int N, int M, int start, int count){
	if(count == M){
		for(int i = 0 ; i < N ; i++){
			if(Select[i] == 1){
				cout<<Arr[i]<<" ";		
			} 
		}
		printf("\n");
	}
	for(int i = start ; i < N ; i++){
		if(Select[i] == true) continue;
		else{
			Select[i] = true;
			Combination(N, M, i, count+1);
			Select[i] = false;
		}
	}	
}
