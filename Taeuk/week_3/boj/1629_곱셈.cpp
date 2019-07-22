#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll powerTo(ll num, ll power, ll div)
{
	if (power == 1) return num % div;
	
	if (power % 2 == 1)
		return num * powerTo(num, power - 1, div) % div;
	else {
		ll res = powerTo(num, power / 2, div);
		return res * res % div;
	}
}

int main()
{
	ll A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);

	printf("%lld", powerTo(A, B, C));

	return 0;
}