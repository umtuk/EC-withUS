#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(vector<int>& list, int left, int right)
{
	int i;
	int low = left;
	int high = right + 1;
	int pivot = list[left];

	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);

		do {
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high) SWAP(list[low], list[high], i);
	} while (low < high);

	SWAP(list[left], list[high], i);

	return high;
}

int quickSort(vector<int>& list, int left, int right)
{
	if (left >= right) return 0;

	int q = partition(list, left, right);

	quickSort(list, left, q - 1);
	quickSort(list, q + 1, right);

	return 0;
}

int main()
{
	vector<int> list = { 38, 27, 43, 9, 3, 82, 10 };
	int size = list.size();

	quickSort(list, 0, size - 1);

	for (int i = 0; i < size; i++)
		printf("%d ", list[i]);

	return 0;
}