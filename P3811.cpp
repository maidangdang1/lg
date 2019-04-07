#include <iostream>
typedef long long ll;
#pragma GCC optimize(3)
using namespace std;
ll inv[3000010];
/*
ll qpow(ll a, ll b, ll mod)
{
	ll temp = a;
	ll cnt = 1;
	while (b != 0)
	{
		if (b & 1)
			cnt = (cnt * temp) % mod;
		b = b >> 1;
		temp = (temp * temp) % mod;
	}
	return cnt;
}
*/
int main()
{
	freopen("test.txt", "r", stdin);
	//ios::sync_with_stdio(false);
	//freopen("2.txt", "w", stdout);
	ll n, p;
	cin >> n >> p;
	ll i;
	//ll inv[n + 10];
	/*
	cout << 1 << endl;
	for (i = 2;i <= n;i++)
		cout << qpow(i, p - 2, p) << endl;
	*/
	inv[1] = 1;
	cout << 1 << endl;
	for (i = 2;i <= n;i++)
	{
		inv[i] = (p - p / i) * inv[p % i] % p;
		printf("%lld\n", inv[i]);
		//cout << inv[i] << endl;
	}
	fclose(stdin);
	//fclose(stdout);
	return 0;
}
