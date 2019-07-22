#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 64

vector<char> res;
char input[SIZE][SIZE + 1];

int compress(int lowY, int highY, int lowX, int highX)
{
	char compare = input[lowY][lowX];
	for (int y = lowY; y < highY; y++) {
		if (compare == '2') break;
		for (int x = lowX; x < highX; x++)
			if (compare != input[y][x]) {
				compare = '2';
				break;
			}
	}
	if (compare != '2') {
		res.push_back(compare);
		return 0;
	}

	int yMean = (lowY + highY) / 2;
	int xMean = (lowX + highX) / 2;
	res.push_back('(');
	compress(lowY, yMean, lowX, xMean);
	compress(lowY, yMean, xMean, highX);
	compress(yMean, highY, lowX, xMean);
	compress(yMean, highY, xMean, highX);
	res.push_back(')');
}

int main()
{
	int N = 0;
	scanf("%d", &N);

	for (int y = 0; y < N; y++)
		scanf("%s", input[y]);

	compress(0, N, 0, N);

	int n = res.size();
	for (int i = 0; i < n; i++)
		printf("%c", res[i]);
}