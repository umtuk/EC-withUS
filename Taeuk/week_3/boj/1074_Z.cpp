#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pow(int num, int power)
{
	int ret = 1;
	for (int i = 0; i < power; i++)
		ret *= num;
	return ret;
}

int order(int N, int r, int c)
{
	if (N == 0) return 0;
	int mean = pow(2, N - 1);

	int ret = 0;
	if (r >= mean) {
		ret += mean * mean * 2;
		r -= mean;
	}
	if (c >= mean) {
		ret += mean * mean;
		c -= mean;
	}
	ret += order(N - 1, r, c);

	return ret;
}

int main()
{
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);

	printf("%d", order(N, r, c));

	return 0;
}