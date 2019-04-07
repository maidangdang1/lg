#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	long long data;
	short color;
	int rank;
};
bool comp(node x, node y)
{
	if (x.data == y.data)
		return x.rank < y.rank;
	else
		return x.data < y.data;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	node a[n + 10];
	int i;
	int x, y;
	for (i = 1; i <= n; i++)
	{
		cin >> x >> y >> a[i].color;
		a[i].data = (x - x0) * (x - x0) + (y - y0) * (y - y0);
		a[i].rank = i;
	}
	sort(a + 1, a + 1 + n, comp);
	int sum = n;
	int red = 0;
	int black = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i].color == 1)
			red++;
		else
			black++;
		if (black > red)
			sum--;
	}
	cout << sum;
	fclose(stdin);
	return 0;
}