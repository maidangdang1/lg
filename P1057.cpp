#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int a[n + 10][m + 10];
	int i;
	memset(a, 0, sizeof(a));
	a[1][0] = 1;
	int j;
	for (i = 1;i <= m;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (j == 1)
				a[j][i] = a[j + 1][i - 1] + a[n][i - 1];
			else if (j == n)
				a[j][i] = a[j - 1][i - 1] + a[1][i - 1];
			else
				a[j][i] = a[j - 1][i - 1] + a[j + 1][i - 1];
		}
	}
	cout << a[1][m];
	fclose(stdin);
	return 0;
}
