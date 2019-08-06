#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> isSelected;
vector<int> selected;

int show()
{
	printf("%d", selected[0]);
	for (int i = 1; i < selected.size(); i++)
		printf(" %d", selected[i]);
	printf("\n");

	return 0;
}

int bruteForce(int N, int M)
{
	if (M == 0) { show(); return 0; }

	for (int i = 1; i <= N; i++)
		if (!isSelected[i]) {
			isSelected[i] = true;
			selected.push_back(i);
			bruteForce(N, M - 1);
			isSelected[i] = false;
			selected.pop_back();
		}

	return 0;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	isSelected.assign(N + 1, false);

	bruteForce(N, M);

	return 0;
}