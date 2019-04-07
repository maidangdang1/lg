#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[2010][2010];
int qzh[2010][2010];
int main()
{
	freopen("test.txt", "r", stdin);
	int t, k;
	cin >> t >> k;
	int i;
	int j;
	int m, n;
	int ans;
	memset(a, 0, sizeof(a));
	memset(qzh, 0, sizeof(qzh));
	for (i = 0;i <= 2000;i++)
		a[i][i] = 1;
	for (i = 0;i <= 2000;i++)
		a[i][0] = 1;
	for (i = 2;i <= 2000;i++)
	{
		for (j = 1;j < i;j++)
			a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % k;
	}
	for (i = 0;i <= 2000;i++)
	{
		for (j = 0;j <= i;j++)
		{
			if (a[i][j] == 0)
				qzh[i][j]++;
		}
	}
	for (i = 0;i <= 2000;i++)
	{
		for (j = 1;j <= i;j++)
			qzh[i][j] += qzh[i - 1][j] + qzh[i][j - 1] - qzh[i - 1][j - 1];
		qzh[i][j] = qzh[i][j - 1];
	}
	//cout << qzh[5][6] << endl;
	/*
	for (i = 0;i <= 10;i++)
	{
		for (j = 0;j <= i;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = 0;i <= 10;i++)
	{
		for (j = 0;j <= i;j++)
			cout << qzh[i][j] << " ";
		cout << endl;
	}
	*/
	while (t--)
	{
		ans = 0;
		cin >> n >> m;
		if (m > n)
			m = n;
		/*
		for (i = 0;i <= n;i++)
		{
			for (j = 0;j <= min(i, m);j++)
			{
				if (a[i][j] == 0)
					ans++;
			}
		}
		cout << ans << endl;
		*/
		cout << qzh[n][m] << endl;
	}
	fclose(stdin);
	return 0;
	/*
	for (i = 0;i <= 10;i++)
	{
		for (j = 0;j <= i;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	*/
}
