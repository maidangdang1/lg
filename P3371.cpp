#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 2147483647;
struct node
{
	int u;
	int v;
	int w;
};
int main()
{
	freopen("text.txt", "r", stdin);
	int n, m, s;
	cin >> n >> m >> s;
	ll dis[n + 10];
	node a[m + 10];
	int first[n + 10];
	int next[m + 10];
	bool vis[n + 10];
	memset(first, -1, sizeof(first));
	memset(next, -1, sizeof(next));
	memset(vis, false, sizeof(vis));
	int i;
	int j;
	int temp;
	for (i = 1;i <= n;i++)
		dis[i] = inf;
	dis[s] = 0;
	vis[s] = true;
	for (i = 1;i <= m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
		next[i] = first[a[i].u];
		first[a[i].u] = i;
	}
	//cout << "Pass line 38" << endl;
	/*
	for (i = 1;i <= n;i++)
		cout << first[i] << endl;
	cout << endl;
	for (i = 1;i <= m;i++)
		cout << next[i] << endl;
	*/
	int k = first[s];
	while (k != -1)
	{
		if (dis[a[k].v] == -1)
			dis[a[k].v] = a[k].w;
		else if (dis[a[k].v] > a[k].w)
			dis[a[k].v] = a[k].w;
		k = next[k];
	}
	//cout << "Pass line 55" << endl;
	/*
	for (i = 1;i <= n;i++)
		cout << dis[i] << " ";
	*/
	for (i = 2;i <= n;i++)
	{
		temp = -1;
		for (j = 1;j <= n;j++)
		{
			if (vis[j] == false && (temp == -1 || dis[j] < dis[temp]))
				temp = j;
		}
		vis[temp] = true;
		k = first[temp];
		while (k != -1)
		{
			if (dis[a[k].v] > dis[temp] + a[k].w)
				dis[a[k].v] = dis[temp] + a[k].w;
			k = next[k];
		}
	}
	for (i = 1;i <= n;i++)
		cout << dis[i] << " ";
	fclose(stdin);
	return 0;
}
