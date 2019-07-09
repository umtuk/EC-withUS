#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPicked(vector<int>& picked)
{
	int N = picked.size();

	printf("%d", picked[0]);
	for (int i = 1; i < N; i++) {
		printf(" %d", picked[i]);
	}
	printf("\n");
}

/*
	순열

	n : 전체 원소의 수
	picked : 지금까지 고른 원소들의 번호
	toPick : 더 고를 원소의 수
*/
void pick(int n, vector<int>& picked, int toPick, vector<bool>& isPicked)
{
	if (toPick == 0) { printPicked(picked); return; }

	for (int next = 0; next < n; next++) {
		if (!isPicked[next]) {
			picked.push_back(next);
			isPicked[next] = true;
			pick(n, picked, toPick - 1, isPicked);
			picked.pop_back();
			isPicked[next] = false;
		}
	}
}

int main()
{
	int n = 7, toPick = 4;
	vector<int> picked;
	vector<bool> isPicked(n, false);

	pick(n, picked, toPick, isPicked);

	return 0;
}