#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fastSum(int n)
{
	if (n == 1) return 1;
	if (n % 2 == 0) return n * n / 4 + fastSum(2 / n);
	return n + fastSum(n - 1);
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d", fastSum(n));

	return 0;
}