#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> selected;

int show()
{
	printf("%d", selected[0]);
	for (int i = 1; i < selected.size(); i++)
		printf(" %d", selected[i]);
	printf("\n");

	return 0;
}

int bruteForce(int N, int M, int next = 1)
{
	if (M == 0) { show(); return 0; }

	for (int i = next; i <= N; i++) {
		selected.push_back(i);
		bruteForce(N, M - 1, i);
		selected.pop_back();
	}

	return 0;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	bruteForce(N, M);

	return 0;
}