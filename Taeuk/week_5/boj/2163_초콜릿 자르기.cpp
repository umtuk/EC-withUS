#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 301

int cache[SIZE][SIZE] = { 0, };

int run(int N, int M)
{
	if (N * M == 1) return 0;
	if (cache[N][M] != 0) return cache[N][M];
	if (N < M) return run(M, N);

	int n = N / 2;
	cache[N][M] = run(n, M) + run(N - n, M) + 1;
	return cache[N][M];
}

int main()
{
	cache[2][1] = 1;
	int N, M;
	scanf("%d %d", &N, &M);

	printf("%d", run(N, M));

	return 0;
}