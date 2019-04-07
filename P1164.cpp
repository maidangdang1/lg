#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int a[n + 10];
	int i;
	for (i = 1;i <= n;i++)
		cin >> a[i];
	int ways[m + 10];
	memset(ways, 0, sizeof(ways));
	int j;
	for (i = 1;i <= n;i++)
	{
		for (j = m;j >= 1;j--)
		{
			if (j < a[i])
				continue;
			else if (j == a[i])
				ways[j]++;
			else
				ways[j] += ways[j - a[i]];
		}
	}
	cout << ways[m];
	fclose(stdin);
	return 0;
}
