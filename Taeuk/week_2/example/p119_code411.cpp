#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

int fastestMaxSum(const vector<int>& A) // O(N)
{
	int N = A.size(), ret = MIN, psum = 0;

	for (int i = 0; i < N; i++) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}

	return ret;
}

int main()
{
	vector<int> A{ -7, 4, -3, 6, 3, -8, 3, 4 };
	int res = 0;

	res = fastestMaxSum(A);
	printf("fastestMaxSum(A) : %d\n", res);

	return 0;
}