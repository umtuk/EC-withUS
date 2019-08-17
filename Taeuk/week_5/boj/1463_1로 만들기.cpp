#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 1000001

int cache[SIZE] = { 0, };

int run(int num)
{
	if (num == 1) return 0;
	if (cache[num] != 0) return cache[num];

	int local_min = numeric_limits<int>::max();
	if (num % 3 == 0) local_min = min(local_min, run(num / 3));
	if (num % 2 == 0) local_min = min(local_min, run(num / 2));
	local_min = min(local_min, run(num - 1));
	cache[num] = local_min + 1;
	return cache[num];
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	printf("%d", run(num));

	return 0;
}