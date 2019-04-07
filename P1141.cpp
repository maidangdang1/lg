#include <iostream>
#include <queue>
//#pragma GCC optimize("Ofast")
using namespace std;
struct node
{
	short data;
	bool vis = false;
};
node a[1010][1010];
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	//node a[n + 10][n + 10];
	queue <int> bfs;
	int i;
	int j;
	int x;
	int y;
	char temp;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			cin >> temp;
			if (temp == '0')
				a[i][j].data = 0;
			else
				a[i][j].data = 1;
		}
	}
	/*
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			cout << a[i][j].data;
		cout << endl;
	}
	*/
	int cnt;
	while (m--)
	{
		cin >> x >> y;
		cnt = 0;
		bfs.push(x);
		bfs.push(y);
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= n;j++)
				a[i][j].vis = false;
		}
		while (bfs.empty() == false)
		{
			x = bfs.front();
			bfs.pop();
			y = bfs.front();
			bfs.pop();
			if (a[x][y].vis)
				continue;
			else
				cnt++;
			a[x][y].vis = true;
			if (a[x][y + 1].data != a[x][y].data && a[x][y + 1].vis == false && y + 1 <= n)
			{
				bfs.push(x);
				bfs.push(y + 1);
			}
			if (a[x][y - 1].data != a[x][y].data && a[x][y - 1].vis == false && y - 1 >= 1)
			{
				bfs.push(x);
				bfs.push(y - 1);
			}
			if (a[x + 1][y].data != a[x][y].data && a[x + 1][y].vis == false && x + 1 <= n)
			{
				bfs.push(x + 1);
				bfs.push(y);
			}
			if (a[x - 1][y].data != a[x][y].data && a[x - 1][y].vis == false && x - 1 >= 1)
			{
				bfs.push(x - 1);
				bfs.push(y);
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	return 0;
}
