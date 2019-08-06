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

int bruteForce(vector<int>& N, int M)
{
	if (M == 0) { show(); return 0; }

	for (int i = 0; i < N.size(); i++)
		if (!isSelected[i]) {
			isSelected[i] = true;
			selected.push_back(N[i]);
			bruteForce(N, M - 1);
			isSelected[i] = false;
			selected.pop_back();
		}

	return 0;
}

int main()
{
	int n, M;
	vector<int> N;
	scanf("%d %d", &n, &M);

	isSelected.assign(n, false);
	N.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &N[i]);
	sort(N.begin(), N.end());

	bruteForce(N, M);

	return 0;
}