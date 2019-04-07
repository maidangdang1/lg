#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int m, n;
	cin >> m >> n;
	int a[m];
	memset(a, 10000, sizeof(a));
	int i;
	int j = 0;
	int k;
	int x;
	int y = 0;
	bool search = false;
	for (i = 1; i <= n; i++)
	{
		if (j == m)
			j = 0;
		cin >> k;
		for (x = 0; x < m; x++)
		{
			if (a[x] == k)
				search = true;
		}
		if (search)
			;
		else
		{
			a[j] = k;
			j++;
			y++;
		}
		search = false;
	}
	cout << y;
	fclose(stdin);
	return 0;
}
