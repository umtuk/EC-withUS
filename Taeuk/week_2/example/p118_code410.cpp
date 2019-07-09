#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

int fastMaxSum(const vector<int>& A, int lo, int hi) // O(NlgN)
{
	if (lo == hi) return A[lo];

	int mid = (lo + hi) / 2;
	int left = MIN, right = MIN, sum = 0;

	for (int i = mid; i >= lo; i--) {
		sum += A[i];
		left = max(left, sum);
	}

	sum = 0;
	for (int i = mid + 1; i <= hi; i++) {
		sum += A[i];
		right = max(right, sum);
	}

	int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));

	return max(left + right, single);
}

int main()
{
	vector<int> A{ -7, 4, -3, 6, 3, -8, 3, 4 };
	int res = 0;

	res = fastMaxSum(A, 0, A.size() - 1);
	printf("fastMaxSum(A, 0, A.size() - 1) : %d\n", res);

	return 0;
}