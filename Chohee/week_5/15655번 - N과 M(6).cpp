#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> Arr;
vector<bool> Select;
void Combination(int n, int r, int start, int count); 

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
	
	Combination(N, M, 0, 0);
	
} 

void Combination(int n, int r, int start, int count){
	if(count == r){
		for(int i = 0 ; i < n ; i++){
			if(Select[i] == true){
				cout<<Arr[i]<<" ";
			}
		}
		printf("\n");
		return;
	}
	for(int i = start; i < n ; i++){
		if(Select[i] == true) continue;
		Select[i] = true;
		Combination(n, r, i, count+1);
		Select[i] = false;
	}
}
