#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> Arr;
vector<int> Select;
void CwithRepetition(int n, int r, int start, int count);

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; i++){
		Arr.push_back(i+1);
		Select.push_back(0);
	}
	CwithRepetition(N, M, 0, 0);	
}

/* 중복조합 구하는 알고리즘 */
void CwithRepetition(int n, int r, int start, int count){
	// 3개를 뽑았을 때 
	if(count == r){
		for(int i = 0 ; i < r ; i++){
			cout<<Select[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	// 3개를 뽑기 위해 실행되는 부분 
	for(int i = start ; i < n ; i++){
		Select[count] = Arr[i];
		CwithRepetition(n, r, i, count+1);
	}
}
