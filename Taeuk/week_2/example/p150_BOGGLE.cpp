#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

char board[5][5] = { 0, };

bool inRange(int y, int x)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 5) return true;
	return false;
}

bool hasWord(int y, int x, const string& word)
{
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;

	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];

		if (hasWord(nextY, nextX, word.substr(1))) 
			return true;
	}

	return false;
}

int main()
{
	string word;

	for (int y = 0; y < 5; y++)
		scanf("%s", board[y]);
	cin >> word;

	for (int x = 0; x < 5; x++)
		for (int y = 0; y < 5; y++)
			if (hasWord(y, x, word)) {
				printf("YES");
				return 0;
			}

	printf("NO");
	return 0;
}
/*
URLPM
XPRET
GIAET
XTNZY
XOQRS

PRETTY
GIRL
REPEAT
*/