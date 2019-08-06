#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 9

int tall[SIZE] = { 0, };
vector<int> picked;
int sum = 0;
int pickedSize = 0;
bool searchEnd = false;

void set(int i, int delta)
{
	sum += tall[i] * delta;
	pickedSize += delta;
}

void search(int start)
{
	if (searchEnd) return;
	if (sum > 100) return;
	if (pickedSize == 7) {
		if (sum == 100) {
			for (int i = 0; i < pickedSize; i++)
				printf("%d\n", picked[i]);
			searchEnd = true;
		}
		return;
	}
	for (int i = start; i < SIZE; i++) {
		set(i, 1);
		picked.push_back(tall[i]);
		search(i + 1);
		set(i, -1);
		picked.pop_back();
	}
}

int main()
{
	for (int i = 0; i < SIZE; i++)
		scanf("%d", &tall[i]);

	sort(tall, tall + SIZE);

	search(0);

	return 0;
}