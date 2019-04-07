#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
struct node
{
	int a;
	int b;
	int w;
};
int main()
{
	freopen("text.txt", "r", stdin);
	int n, m, v, e;
	cin >> n >> m >> v >> e;
	int i;
	int c[n + 10];
	int d[n + 10];
	double k[n + 10];
	node road[e + 10];
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	memset(k, 0, sizeof(k));
	for (i = 1;i <= n;i++)
		cin >> c[i];
	for (i = 1;i <= n;i++)
		cin >> d[i];
	for (i = 1;i <= n;i++)
		cin >> k[i];
	for (i = 1;i <= e;i++)
		cin >> road[i].a >> road[i].b >> road[i].w;
	//road[1].a = 1;
	//cout << road[1].a << endl;
	double ans = 0.000;
	int dis[30][30];
	memset(dis, 0, sizeof(dis));
	int j;
	if (n <= 1)
	{
		ans = 0.000;
		goto F;
	}
	else
	{
		if (m == 0)
		{
			for (j = 1;j <= e;j++)
			{
				if (dis[road[j].a][road[j].b] == 0 || dis[road[j].a][road[j].b] > road[j].w)
				{
					dis[road[j].a][road[j].b] = road[j].w;
					dis[road[j].b][road[j].a] = road[j].w;
				}
			}
			for (i = 1;i < n;i++)
				ans += dis[road[i].a][road[i].b];
		}
	}
	F:
	cout << setprecision(2) << fixed << ans;
	fclose(stdin);
	return 0;
}
