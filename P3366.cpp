#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;
int fa[5010];
struct edge
{
	int u;
	int v;
	int w;
};
int f(int x)
{
	if (fa[x] == x)
		return x;
	else
	{
		fa[x] = f(fa[x]);
		return fa[x];
	}
}
bool comp(edge x, edge y)
{
	return x.w < y.w;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	edge a[m + 10];
	int i;
	ll cnt = 0;
	int num = 0;
	for (i = 1;i <= m;i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (i = 1;i <= n;i++)
		fa[i] = i;
	sort(a + 1, a + 1 + m, comp);
	for (i = 1;num < n - 1;i++)
	{
		if (f(a[i].u) == f(a[i].v))
			continue;
		else
		{
			fa[f(a[i].v)] = fa[f(a[i].u)];
			cnt += a[i].w;
			num++;
		}
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
