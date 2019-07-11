#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
bool areFriends[10][10];

int countPairings(bool taken[10])
{
	int firstFree = -1;

	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main()
{
	int C = 0;
	int m = 0;
	int one, other;
	bool taken[10];

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		for (int i = 0; i < 10; i++) taken[i] = false;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				areFriends[i][j] = false;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &one, &other);
			if (one <= other)
				areFriends[one][other] = true;
			else
				areFriends[other][one] = true;
		}

		printf("%d\n", countPairings(taken));
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