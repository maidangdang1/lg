#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int u;
	int v;
	int w;
};
bool comp(node x, node y)
{
	return x.w < y.w;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n + 10];
	memset(a, 0, sizeof(a));
	node edge[m + 10];
	int i;
	for (i = 1;i <= m;i++)
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	sort(edge + 1, edge + 1 + m, comp);
	int cnt = 1;
	int sum = 0;
	for (i = 1;i <= m;i++)
	{
		if (edge[i].u == edge[i].v && a[edge[i].u] != 0)
			continue;
		else
		{
			if (edge[i].u == 0 && edge[i].v == 0)
			{
				a[edge[i].u] = a[edge[i].v] = cnt;
				cnt++;
			}
			else if ()
		}
	}
}