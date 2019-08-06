#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isHan(int num, int pcRemaind, int cRemaind)
{
	if (num == 0) return true;
	int remaind = num % 10;
	if (isHan(num / 10, cRemaind, remaind) &&
		(pcRemaind - cRemaind) == (cRemaind - remaind))
		return true;
	else
		return false;
}

int main()
{
	int N = 0, result = 0;
	int num = 0, pcRemaind = 0, cRemaind = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		num = i;
		pcRemaind = num % 10;
		num /= 10;
		cRemaind = num % 10;

		if (isHan(num / 10, pcRemaind, cRemaind)) result++;
	}
	printf("%d", result);

	return 0;
}