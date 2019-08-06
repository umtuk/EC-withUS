#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R = 0, B = 0;
int RaB = 0;
int L = 0; int W = 0;

int findSquareRootRoundUp(int num)
{
	int n = 0;
	while (num > n * n)
		n++;
	return n;
}

void search()
{
	int local_L = RaB, local_R = 0;
	int min_L = findSquareRootRoundUp(RaB);

	while (local_L >= min_L) {
		if (RaB % local_L == 0) {
			local_R = RaB / local_L;
			if (2 * (local_L + local_R - 2) == R) {
				L = local_L;
				R = local_R;
				return;
			}
		}

		local_L--;
	}
}

int main()
{
	scanf("%d %d", &R, &B);
	RaB = R + B;

	search();

	printf("%d %d", L, R);

	return 0;
}