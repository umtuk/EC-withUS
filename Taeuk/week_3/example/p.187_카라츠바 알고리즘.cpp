#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void normalization(vector<int>& num)
{
	num.push_back(0);

	for (int i = 0; i < num.size() - 1; i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	normalization(c);

	return c;
}


void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int an = a.size(), bn = b.size();
	a.resize(an > bn ? an + k : bn + k, 0);
	for (int i = 0; i < bn; i++)
		a[i + k] += b[i];
	normalization(a);
}
void subFrom(vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < b.size(); i++)
		a[i] -= b[i];
	normalization(a);
}

vector<int> karatusba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();

	if (an < bn) return karatusba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatusba(a1, b1);
	vector<int> z0 = karatusba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatusba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}

void setbigInt(vector<int>& a, string s)
{
	int size = s.size();
	a.assign(size, 0);
	for (int i = size - 1; i >= 0; i--)
		a[size - 1 - i] = s[i] - '0';
}

int main()
{
	vector<int> a, b, c;
	string s1, s2;

	cin >> s1;
	cin >> s2;
	setbigInt(a, s1);
	setbigInt(b, s2);

	c = karatusba(a, b);
	for (int i = c.size() - 1; i >= 0; i--)
		printf("%d", c[i]);

	return 0;
}