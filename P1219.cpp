#include <iostream>
#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast")
using namespace std;
struct node
{
	short data;
	int pd = 0;
};
node queen[15][15];
short mark[15];
int cnt = 0;
short n;
inline void book(int i, int j)
{
	int x;
	for (x = 1;x <= n;x++)
		queen[x][j].pd++;
	int y;
	x = i;
	y = j;
	while (i > 1 && j > 1)
	{
		i--;
		j--;
	}
	while (i <= n && j <= n)
	{
		queen[i][j].pd++;
		i++;
		j++;
	}
	while (x > 1 && y < n)
	{
		x--;
		y++;
	}
	while (x <= n && y >= 1)
	{
		queen[x][y].pd++;
		x++;
		y--;
	}
}
inline void clr(int i, int j)
{
	int x;
	for (x = 1;x <= n;x++)
		queen[x][j].pd--;
	int y;
	x = i;
	y = j;
	while (i > 1 && j > 1)
	{
		i--;
		j--;
	}
	while (i <= n && j <= n)
	{
		queen[i][j].pd--;
		i++;
		j++;
	}
	while (x > 1 && y < n)
	{
		x--;
		y++;
	}
	while (x <= n && y >= 1)
	{
		queen[x][y].pd--;
		x++;
		y--;
	}
}
void dfs(int floor)
{
	int i;
	//int j;
	if (floor == n + 1)
	{
		if (cnt < 3)
		{
			for (i = 1;i <= n;i++)
				cout << mark[i] << " ";
			cout << endl;
		}
		cnt++;
		return;
	}
	for (i = 1;i <= n;i++)
	{
		if (queen[floor][i].data == 0 && queen[floor][i].pd == 0)
		{
			queen[floor][i].data = 1;
			book(floor, i);
			//cout << queen[6][6].pd << endl;
			if (cnt < 3)
				mark[floor] = i;
			dfs(floor + 1);
			queen[floor][i].data = 0;
			clr(floor, i);
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n;
	dfs(1);
	cout << cnt;
	fclose(stdin);
	return 0;
}
