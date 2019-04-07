#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
typedef long long ll;
using namespace std;
struct node
{
	int data;
	int rank;
};
bool comp(node x, node y)
{
	if (x.data == y.data)
		return x.rank < y.rank;
	return x.data < y.data;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	node a[n + 10];
	bool vis[n + 10][n + 10];
	memset(vis, false, sizeof(vis));
	int i;
	for (i = 1;i <= n;i++)
		cin >> a[i].data;
	for (i = 1;i <= n;i++)
		a[i].rank = i;
	int magic[n + 10][n + 10];
	int j;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			cin >> magic[i][j];
	}
	int temp;
	ll cnt = 0;
	//int j;
	sort(a + 1, a + 1 + n, comp);
	for (i = 1;i <= n;i++)
	{
		temp = 0;
		for (j = 1;j <= n;j++)
		{
			if (vis[a[i].rank][j] == false)
				temp += magic[a[i].rank][j];
		}
		cnt += temp * a[i].data;
		for (j = 1;j <= n;j++)
		{
			vis[j][a[i].rank] = true;
			vis[a[i].rank][j] = true;
		}
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
