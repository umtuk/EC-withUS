#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
	int one;
	int other;
} edge;

int pick(int n, vector<edge>& mate, vector<bool>& picked, int toPick, int smallest)
{
	if (toPick == 0) return 1;

	int result = 0;

	for (int next = smallest; next < n; next++) {
		if (!(picked[mate[next].one] || picked[mate[next].other])) {
			picked[mate[next].one] = true; picked[mate[next].other] = true;
			result += pick(n, mate, picked, toPick - 1, next + 1);
			picked[mate[next].one] = false; picked[mate[next].other] = false;
		}
	}

	return result;
}

int main()
{
	int C = 0, n = 0, m = 0;
	edge e = { 0, 0 };

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d %d", &n, &m);
		vector<edge> mate;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &e.one, &e.other);
			mate.push_back(e);
		}
		vector<bool> picked(n, false);

		printf("%d\n", pick(m, mate, picked, n / 2, 0));
	}
}
/*
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
*/