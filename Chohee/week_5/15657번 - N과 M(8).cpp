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
		int input;
		scanf("%d", &input);
		Arr.push_back(input);
		Select.push_back(0);
	}
	// �������� 
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N-1 ; j++){
			if(Arr[j] > Arr[j+1]){
				int tmp = Arr[j+1];
				Arr[j+1] = Arr[j];
				Arr[j] = tmp;
			}
		}
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
