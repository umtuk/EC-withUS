#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> Arr;
vector<bool> Select;
vector<int> vec;
void Permutation(int n, int r, int count);

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
	
	Permutation(N, M, 0);
	
} 

void Permutation(int n, int r, int count){
	if(count == r){
		for(int i = 0 ; i < vec.size() ; i++){
			cout<<vec[i]<<" ";
		}
		cout<<"\n";
		return;  
	}
	for(int i = 0 ; i < n ; i++){
		if(Select[i] == true) continue;
		else{
			Select[i] = true;
			vec.push_back(Arr[i]);
			Permutation(n, r, count+1);
			vec.pop_back();
			Select[i] = false;
		}		
	}
}
