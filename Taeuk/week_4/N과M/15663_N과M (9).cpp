#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> selected;
vector<int> cnt;

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
		if (cnt[i] != 0) {
			cnt[i]--;
			selected.push_back(N[i]);
			bruteForce(N, M - 1);
			cnt[i]++;
			selected.pop_back();
		}

	return 0;
}

int main()
{
	int n, M;
	vector<int> N;
	scanf("%d %d", &n, &M);

	cnt.assign(n, 0);
	N.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &N[i]);
	sort(N.begin(), N.end());

	for (int i = 0, j = 0, cpr = N[j]; i < N.size(); i++) {
		if (cpr == N[i]) { cnt[j]++; }
		else {
			cnt[++j]++;
			cpr = N[i];
		}
	}

	N.erase(unique(N.begin(), N.end()), N.end());
	cnt.resize(N.size());


	bruteForce(N, M);

	return 0;
}