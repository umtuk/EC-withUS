#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 500000
int A[SIZE];
int N = 0;
vector<int> sorted;
int res = 0;

int merge(int left, int mid, int right)
{
	int l = left;
	int m = mid + 1;
	int next = left;

	while (l <= mid && m <= right)
		if (A[l] < A[m])
			sorted[next++] = A[l++];
		else {
			sorted[next++] = A[m++];
			res += m - next;
		}

	if (l <= mid)
		for (int i = l; i <= mid; i++)
			sorted[next++] = A[i];
	else
		for (int i = m; i <= right; i++)
			sorted[next++] = A[i];

	printf("%d %d\n", left, right);
	for (int i = left; i <= right; i++) {
		A[i] = sorted[i];
		printf("%d ", A[i]);
	}
	printf("\n\n");

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
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	mergeSort(0, N - 1);

	printf("%d", res);

	return 0;
}