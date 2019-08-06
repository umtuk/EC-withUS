#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#define SIZE 500000

int A[SIZE];
int N;
int res = 0;

int bubbleSort()
{
	int temp;
	for (int i = 0; i < N; i++)
		for (int j = N - 1; j > i; j--)
			if (A[j] < A[j - 1]) {
				SWAP(A[j], A[j - 1], temp);
				res++;
			}

	return 0;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	bubbleSort();

	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n%d", res);

	return 0;
}