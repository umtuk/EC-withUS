#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10
const int INF = numeric_limits<int>::max();

int n;
double dist[MAX][MAX];

double shortestPath(vector<int>& path, vector<bool> visited, double currentLength)
{
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];

	double ret = INF;

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;

		int here = path.back();

		path.push_back(next);
		visited[next] = true;

		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);

		visited[next] = false;
		path.pop_back();
	}

	return ret;
}