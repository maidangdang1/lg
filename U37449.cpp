#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int deep[m + 10];
	memset(deep, 0, sizeof(deep));
	int i;
	int v, x;
	int j;
	int up;
	int down;
	int cnt;
	for (i = 1;i <= n;i++)
	{
		cin >> v >> x;
		up = min(x + 2 * v, m);
		cnt = v - 1;
		for (j = x + 1;j <= up;j++)
		{
			deep[j] -= cnt;
			cnt--;
		}
		cnt++;
		cnt++;
		down = min(x + 3 * v, m);
		for (j = x + 2 * v + 1;j <= down;j++)
		{
			deep[j] -= cnt;
			cnt++;
		}
		up = max(1, x - 2 * v + 1);
		cnt = v;
		for (j = x;j >= up;j--)
		{
			deep[j] -= cnt;
			cnt--;
		}
		down = max(x - 3 * v + 1, 1);
		for (j = x - 2 * v;j >= down;j--)
		{
			deep[j] -= cnt;
			cnt++;
		}
		/*
		for (j = 1;j <= m;j++)
			cout << deep[j] << " ";
		cout << endl;
		*/
	}
	/*
	for (i = 1;i <= m;i++)
		deep[i] += deep[i - 1];
	*/
	for (i = 1;i <= m;i++)	
		cout << deep[i] << " ";
	fclose(stdin);
	return 0;
}
