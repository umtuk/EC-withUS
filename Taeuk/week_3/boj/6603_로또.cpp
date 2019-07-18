#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k = 0;
vector<int> S;
vector<int> picked;

void C(int toPick, int smallest)
{
	if (toPick == 0) {
		printf("%d", picked[0]);
		for (int i = 1; i < 6; i++)
			printf(" %d", picked[i]);
		printf("\n");
		return;
	}

	for (int next = smallest; next < k; next++) {
		picked.push_back(S[next]);
		C(toPick - 1, next + 1);
		picked.pop_back();
	}
}

int main()
{
	int n = 0;

	while (true) {
		scanf("%d", &k);
		if (k == 0) break;

		S.assign(k, 0);
		for (int i = 0; i < k; i++) {
			scanf("%d", &n);
			S[i] = n;
		}

		C(6, 0);
		printf("\n");
	}

	return 0;
}