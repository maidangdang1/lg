#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
/*
ll qpow(ll b, ll p, ll k)
{
	if (p == 1)
		return b % k;
	if (p == 2)
		return b * b % k;
	if (p % 2)
		return qpow(b, p / 2, k) % k * qpow(b, p / 2, k) % k * b % k;
	else
		return qpow(b, p / 2, k) % k * qpow(b, p / 2, k) % k;
}
*/
int main()
{
	freopen("test.txt", "r", stdin);
	ll b, p ,k;
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=";
	ll sum = 1;
	while (p)
	{
		if (p % 2)
			sum = sum * b % k;
		b = b * b % k;
		p = p >> 1;
	}
	cout << sum % k;
	return 0;
	//cout << qpow(b, p, k);
	fclose(stdin);
	return 0;
}
