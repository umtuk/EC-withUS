#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binarization(unsigned long long num)
{
	if (num == 0) return;

	binarization(num / 2);
	printf("%d", num % 2);
}

int main()
{
	unsigned long long num = 0;
	scanf("%lld", &num);

	binarization(num);

	return 0;
}