#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
typedef long long ll;
using namespace std;
const ll mod = 11111597780929;
ll qpow(int a, int b)
{
	ll temp = a;
	ll cnt = 1;
	while (b != 0)
	{
		if (b & 1)
			cnt *= temp;
		cnt %= mod;
		a = a >> 1
		temp *= temp;
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int i;
	int a[n + 10];
	int qzh[n + 10];
	int cf[n + 10];
	a[0] = 0;
	for (i = 1;i <= n;i++)
		cin >> a[i];
	memset(qzh, 0, sizeof(qzh));
	memset(cf, 0, sizeof(cf));
	for (i = 1;i <= n;i++)
		qzh[i] = qzh[i - 1] + a[i];
	int opt;
	int l;
	int r;
	int temp;
	double k;
	int cnt = 0;
	while (m--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> l >> r >> temp;
			cf[l] += temp;
			cf[r + 1] -= temp;
		}
		else
		{
			temp = 0;
			cnt = 0;
			for (i = 1;i <= n;i++)
			{
				cnt += cf[i];
				temp += cnt;
				qzh[i] += temp;
			}
			cin >> l >> r;
			k = (double)(qzh[r] - qzh[l - 1]) / (double)(r - l + 1);
			cout << (int)k % mod << endl;
		}
	}
	fclose(stdin);
}
