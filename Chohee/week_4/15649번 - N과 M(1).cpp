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
	for(int i = 1 ; i <= N ; i++){
		Arr.push_back(i);
		Select.push_back(0);
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
