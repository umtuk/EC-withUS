#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 46

int cache[SIZE] = { 0, 1, };

int fibo(int n)
{
	if (n == 0) return 0;
	if (cache[n] != 0) return cache[n];

	cache[n] = fibo(n - 1) + fibo(n - 2);
	return cache[n];
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d", fibo(n));

	return 0;
}