#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

int inefficientMaxSum(const vector<int>& A) // O(N^3)
{
	int N = A.size(), ret = MIN;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int sum = 0;

			for (int k = i; k <= j; k++) {
				sum += A[k];
			}
			ret = max(ret, sum);
		}
	}

	return ret;
}

int betterMaxSum(const vector<int>& A) // O(N^2)
{
	int N = A.size(), ret = MIN;

	for (int i = 0; i < N; i++) {
		int sum = 0;

		for (int j = i; j < N; j++) {
			sum += A[j];
			ret = max(ret, sum);
		}
	}

	return ret;
}

int main()
{
	vector<int> A{ -7, 4, -3, 6, 3, -8, 3, 4 };
	int res = 0;

	res = inefficientMaxSum(A);
	printf("inefficientMaxSum(A) : %d\n", res);

	res = betterMaxSum(A);
	printf("betterMaxSum(A) : %d\n", res);

	return 0;
}