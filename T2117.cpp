#include <iostream>
using namespace std;
int last(int k)
{
	int i;
	for (i = 1;i < k;i++)
	{
		if (k % i != 0)
			return i;
	}
}
int a[1000010];
const int mod = 1000000007;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	a[2] = 1;
	int i;
	for (i = 3;i <= 1000000;i++)
		a[i] = last(i);
	for (i = 3;i <= 1000000;i++)
		a[i] = a[a[i]] + 1;
	int cnt = 1;
	for (i = 2;i <= n;i++)
	{
		cnt *= a[i];
		cnt %= mod;
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
