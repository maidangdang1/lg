#include <iostream>
#include <queue>
using namespace std;
struct node
{
	short data = 0;
	bool out = false;
};
node a[40][40];
int n;
void bfs()
{
	int i;
	int j;
	queue <int> b;
	b.push(0);
	b.push(0);
	while (b.empty() == false)
	{
		i = b.front();
		b.pop();
		j = b.front();
		b.pop();
		if (a[i][j].data == 0)
		{
			if (a[i - 1][j].data != 1 && i != 0 && a[i - 1][j].out == false)
			{
				b.push(i - 1);
				b.push(j);
			}
			if (a[i][j - 1].data != 1 && j != 0 && a[i][j - 1].out == false)
			{
				b.push(i);
				b.push(j - 1);
			}
			if (a[i + 1][j].data != 1 && i != n + 1 && a[i + 1][j].out == false)
			{
				b.push(i + 1);
				b.push(j);
			}
			if (a[i][j + 1].data != 1 && j != n + 1 && a[i][j + 1].out == false)
			{
				b.push(i);
				b.push(j + 1);
			}
			a[i][j].out = true;
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n;
	int i;
	int j;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			cin >> a[i][j].data;
	}
	bfs();
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (a[i][j].out == false && a[i][j].data == 0)
				cout << 2 << " ";
			else
				cout << a[i][j].data << " ";
		}
		cout << endl;
	}
	fclose(stdin);
	return 0;
}
