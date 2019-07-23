#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SIZE = 0;
const int dx[4] = { 2, 3, 0, 1 };

vector<char> reverse(vector<char>& original, int index)
{
	vector<char> ret(SIZE, '.');
	int i, j, s;
	vector<vector<char> > local_reverse;
	for (i = 0; i < 4; i++) {
		if (original[index] == 'x') {
			local_reverse[i].push_back(original[index]);
			local_reverse[i].insert(local_reverse[i].end(), reverse(original, index));
		}
		else
			local_reverse[i].push_back(original[index]);
	}

	for (i = 0; i < 4; i++) {
		s = local_reverse[i].size();
		for (j = 0; j < s; j++)
			ret[index++] = local_reverse[dx[i]][j];
	}

	return ret;
}

int main()
{
	int C = 0;
	scanf("%d", &C); getchar();
	char ch;
	char* input;
	vector<char> original(1001, '.');

	for (int i = 0; i < C; i++) {
		SIZE = 0;
		while ((ch = getchar()) != '\n')
			original[SIZE++] = ch;

		original.resize(SIZE);

		reverse(original, 0);
	}
}