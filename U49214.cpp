#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int a[1000010];
int b[1000010];
inline void co(int l)
{
	int m;
	for (m = 1;m <= l;m++)
		a[m] = b[m];
}
int main()
{
	freopen("test.txt", "r", stdin);
	int t;
	cin >> t;
	int n;
	int i;
	int j;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n;
		a[1] = 1;
		for (i = 2;i <= n;i++)
		{
			b[1] = 1;
			for (j = 2;j <= i;j++)
				b[j] = (b[j - 1] + a[j - 1] + a[j]) % 998244353;
			co(i);
		}
		cout << a[n] << endl;
	}
	fclose(stdin);
	//cout << sizeof(a) / 1024 / 1024;
	return 0;
}
