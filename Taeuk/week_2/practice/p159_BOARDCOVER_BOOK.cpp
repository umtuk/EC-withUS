#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}},
};

bool set(vector<vector<int> >& board, int y, int x, int type, int delta)
{
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}

	return ok;
}

int cover(vector<vector<int> >& board) {
	int y = -1, x = -1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++)
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != -1) break;
	}

	if (y == -1) return 1;

	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}

	return ret;
}

int main()
{
	int C = 0, H = 0, W = 0;
	int black = 0;
	char str[21];
	vector<vector<int> > board;

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		black = 0;

		scanf("%d %d", &H, &W);

		board.assign(H, vector<int>(W, 0));

		for (int y = 0; y < H; y++) {
			scanf("%s", str);
			for (int x = 0; x < W; x++)
				if (str[x] == '#') {
					board[y][x] = 1;
					black++;
				}
		}
		if ((H * W - black) % 3 == 0)
			printf("%d\n", cover(board));
		else
			printf("0\n");
	}

	return 0;
}
/*
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
*/