#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	freopen("test.txt", "r", stdin);
	int n, a, b;
	cin >> n >> a >> b;
	queue <int> bfs;
	int cnt = 0;
	int i;
	int floor[n + 10];
	for (i = 1;i <= n;i++)
		cin >> floor[i];
	bool vis[n + 10];
	memset(vis, false, sizeof(vis));
	bfs.push(a);
	bfs.push(floor[a]);
	bfs.push(0);
	int t1, t2, t3;
	if (a == b)
	{
		cout << 0;
		fclose(stdin);
		return 0;
	}
	while (bfs.empty() == false)
	{
		t1 = bfs.front();
		bfs.pop();
		t2 = bfs.front();
		bfs.pop();
		t3 = bfs.front();
		bfs.pop();
		if (vis[t1])
			continue;
		vis[t1] = true;
		if (t1 - t2 > 0)
		{
			bfs.push(t1 - t2);
			bfs.push(floor[t1 - t2]);
			bfs.push(t3 + 1);
		}
		if (t1 + t2 <= n)
		{
			bfs.push(t1 + t2);
			bfs.push(floor[t1 + t2]);
			bfs.push(t3 + 1);
		}
		if (vis[b])
		{
			cout << t3;
			fclose(stdin);
			return 0;
		}
	}
	cout << -1;
	fclose(stdin);
	return 0;
}
