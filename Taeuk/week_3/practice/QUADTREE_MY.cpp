#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SIZE = 0;
const int dx[4] = { 2, 3, 0, 1 };
vector<char> original(1001, '.');
vector<char> reversed(1001, '.');

void merge(int local[5])
{
	int low, high;
	int next = local[0];

	for (int i = 0; i < 4; i++) {
		low = local[dx[i]]; 
		high = local[dx[i] + 1];
		for (int j = low; j < high; j++) {
			reversed[next++] = original[j];
		}
	}

	for (int i = local[0]; i < local[4]; i++)
		original[i] = reversed[i];
}

int reverse(int left, int right)
{
	vector<char> ret(SIZE, '.');
	int next = left;
	int cnt = 1;
	int local[5] = { left, };
	local[4] = -1;

	while (next < SIZE && cnt < 5)
		if (original[next] == 'x')
			local[cnt++] = next = reverse(next + 1, right);
		else
			local[cnt++] = ++next;

	if (local[4] != -1)
		merge(local);

	return next;
}

int main()
{
	int C = 0;
	scanf("%d", &C); getchar();
	char ch;

	for (int i = 0; i < C; i++) {
		SIZE = 0;
		original.resize(1001);
		while ((ch = getchar()) != '\n')
			original[SIZE++] = ch;

		original.resize(SIZE);
		reversed.resize(SIZE);

		reverse(0, SIZE);

		for (int i = 0; i < SIZE; i++)
			printf("%c", original[i]);
		printf("\n");
	}

	return 0;
}