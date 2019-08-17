#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 301

int value[SIZE] = { 0, };
int cache[SIZE] = { 0, };

int run(int n)
{
	if (n < 0) return 0;
	if (n == 0) return 0;
	if (cache[n] != 0) return cache[n];

	int local_max = max(run(n - 2), value[n - 1] + run(n - 3));
	cache[n] = local_max + value[n];
	return cache[n];
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &value[i]);

	printf("%d", run(n));

	return 0;
}