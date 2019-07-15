#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 상수
#define XSIZE 16 // clock 개수
#define YSIZE 10 // switch 개수
const int MAX = numeric_limits<int>::max();

// 고정 조건
vector<vector<int> > switchs({
	vector<int>({0, 1, 2}),
	vector<int>({3, 7, 9, 11}),
	vector<int>({4, 10, 14, 15}),
	vector<int>({0, 4, 5, 6, 7}),
	vector<int>({6, 7, 8, 10, 12}),
	vector<int>({0, 2, 14, 15}),
	vector<int>({3, 14, 15}),
	vector<int>({4, 5, 7, 14, 15}),
	vector<int>({1, 2, 3, 4, 5}),
	vector<int>({3, 4, 5, 9, 13})
	});
bool isLinked[XSIZE][YSIZE] = { false, };

// 입력 변수
int clocks[XSIZE] = { 0, };

// 초기 설정 필요 변수
bool isCorrect[XSIZE] = { false, };
int nPress[YSIZE] = { 0, };
int MIN = 0;

// 임시 변수
int nx = 0;


void set(int y, int delta)
{
	for (int x = 0; x < switchs[y].size(); x++) {
		nx = switchs[y][x];
		if (((clocks[nx] += 3 * delta) %= 12) == 0)
			isCorrect[nx] = true;
		else
			isCorrect[nx] = false;
	}
}

bool isAllCorrect()
{
	for (int i = 0; i < XSIZE; i++)
		if (!isCorrect[i])
			return false;
	return true;
}

void run(int localMin, int sNum)
{
	if (localMin >= MIN) return;

	if (isAllCorrect()) {
		MIN = localMin;
		return;
	}

	if (sNum == YSIZE) return;

	while (nPress[sNum] != 4) {
		set(sNum, nPress[sNum]);
		run(localMin + nPress[sNum], sNum + 1);
		set(sNum, -nPress[sNum]);
		nPress[sNum]++;
	}
	nPress[sNum] = 0;
}

int main()
{
	for (int y = 0; y < YSIZE; y++)
		for (int x = 0; x < switchs[y].size(); x++) {
			nx = switchs[y][x];
			isLinked[nx][y] = true;
		}

	int C = 0;
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		MIN = MAX;

		for (int y = 0; y < YSIZE; y++)
			nPress[y] = 0;

		for (int x = 0; x < XSIZE; x++) {
			scanf("%d", &clocks[x]);
			if ((clocks[x] %= 12) == 0)
				isCorrect[x] = true;
			else
				isCorrect[x] = false;
		}

		run(0, 0);
		if (MIN == MAX)
			printf("-1\n");
		else
			printf("%d\n", MIN);
	}
}
/*
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
*/