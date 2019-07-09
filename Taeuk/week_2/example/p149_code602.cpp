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
	조합

	n : 전체 원소의 수
	picked : 지금까지 고른 원소들의 번호
	toPick : 더 고를 원소의 수
*/
void pick(int n, vector<int>& picked, int toPick)
{
	if (toPick == 0) { printPicked(picked); return; }

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main()
{
    int n = 7, toPick = 4;
	vector<int> picked;

	pick(n, picked, toPick);

	return 0;
}