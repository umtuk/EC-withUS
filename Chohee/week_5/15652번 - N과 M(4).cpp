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

/* �ߺ����� ���ϴ� �˰��� */
void CwithRepetition(int n, int r, int start, int count){
	// 3���� �̾��� �� 
	if(count == r){
		for(int i = 0 ; i < r ; i++){
			cout<<Select[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	// 3���� �̱� ���� ����Ǵ� �κ� 
	for(int i = start ; i < n ; i++){
		Select[count] = Arr[i];
		CwithRepetition(n, r, i, count+1);
	}
}
