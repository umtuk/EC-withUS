#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
	int one;
	int other;
} edge;

void pick(int n, vector<int>& picked, vector<bool>& isMatched)
{

}

int main()
{
	int C = 0, n = 0, m = 0;
	vector<edge> v;
	edge e = { 0, 0 };

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &e.one, &e.other);
			v.push_back(e);
		}
		vector<bool> isMatched(n, false);
	}
}