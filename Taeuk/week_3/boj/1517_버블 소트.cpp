#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int N = 0;
vector<int> A;
vector<int> sorted;
ll res = 0;

int merge(int left, int mid, int right)
{
	int i;
	int l = left;
	int m = mid + 1;
	int next = left;

	while (l <= mid && m <= right)
		if (A[l] <= A[m])
			sorted[next++] = A[l++];
		else {
			sorted[next++] = A[m++];
			res += m - next;
		}

	if (l <= mid)
		for (i = l; i <= mid; i++)
			sorted[next++] = A[i];
	else
		for (i = m; i <= right; i++)
			sorted[next++] = A[i];

	for (i = left; i <= right; i++)
		A[i] = sorted[i];

	return 0;
}

int mergeSort(int left, int right)
{
	if (left >= right) return 0;
	int mid = (left + right) / 2;

	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);

	return 0;
}

int main()
{
	scanf("%d", &N);
	sorted.assign(N, 0);
	A.assign(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	mergeSort(0, N - 1);

	printf("%lld", res);

	return 0;
}