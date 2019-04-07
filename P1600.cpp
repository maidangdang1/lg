#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
struct node
{
	int u;
	int v;
};
struct game
{
	int s;
	int t;
};
int main()
{
	freopen("text.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int i;
	node a[n + 10];
	bool line = true;
	for (i = 1;i < n;i++)
	{
		cin >> a[i].u >> a[i].v;
		if (abs(a[i].u - a[i].v) != 1)
			line = false;
	}
	int visitor[n + 10];
	bool vis0 = true;
	for (i = 1;i <= n;i++)
	{
		cin >> visitor[i];
		if (visitor[i])
			vis0 = false;
	}
	game player[m + 10];
	bool same = true;
	for (i = 1;i <= m;i++)
	{
		cin >> player[i].s >> player[i].t;
		if (player[i].s - player[i].t)
			same = false;
	}
	int ans[n + 10];
	memset(ans, 0, sizeof(ans));
	int temp1, temp2;
	int j;
	if (same)
	{
		for (i = 1;i <= m;i++)
		{
			if (visitor[player[i].t] == 0)
				ans[player[i].t]++;
		}
		goto F;
	}
	else if (vis0)
	{
		for (i = 1;i <= m;i++)
			ans[player[i].s]++;
		goto F;
	}
	else if (line)
	{
		for (i = 1;i <= m;i++)
		{
			temp1 = player[i].s;
			temp2 = player[i].t;
			if (temp1 < temp2)
			{
				for (j = temp1;j <= temp2;j++)
				{
					if (j - temp1 == visitor[j])
						ans[j]++;
				}
			}
			else
			{
				for (j = temp1;j >= temp2;j--)
				{
					if (temp1 - j == visitor[j])
						ans[j]++;
				}
			}
		}
	}
	F:
	for (i = 1;i <= n;i++)
		cout << ans[i] << " ";
	fclose(stdin);
	return 0;
}
