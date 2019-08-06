#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int height[20001] = { 0, };
int N = 0;

int findMax(int left, int right)
{
	if (left == right - 1) return height[left];

	int mid = (left + right) / 2;
	int i, cnt, next_l, next_r;

	int local_max = max(findMax(left, mid), findMax(mid, right));
	int mid_min = min(height[mid - 1], height[mid]);

	i = mid_min;
	cnt = 2; next_l = mid - 2; next_r = mid + 1;
	while (i != 0) {
		if (local_max >= i * N) break;

		while (next_l >= 0 && height[next_l] >= i) {
			cnt++; next_l--;
		}

		while (next_r < N && height[next_r] >= i) {
			cnt++; next_r++;
		}

		local_max = max(local_max, i * cnt);
		i--;
	}

	return local_max;
}

int main()
{
	int C = 0;
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &height[i]);

		printf("%d\n", findMax(0, N));
	}

	return 0;
}