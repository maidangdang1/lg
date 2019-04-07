#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int data;
	int num;
};
bool comp(node x, node y)
{
	if (x.data == y.data)
		return x.num < y.num;
	return x.data < y.data;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int i;
	node a[n + 10];
	for (i = 1;i <= n;i++)
		a[i].num = i;
	for (i = 1;i <= n;i++)
		cin >> a[i].data;
	sort(a + 1, a + 1 + n, comp);
	int p1;
	int p2;
	p1 = 1;
	p2 = n;
	while (p2 != p1)
	{
		if (a[p2].num > a[p1].num)
		{
			cout << a[p2].data - a[p1].data;
			fclose(stdin);
			return 0;
		}
		else
		{
			if (a[p1 + 1].data - a[p1].data <= a[p2].data - a[p2 - 1].data)
				p1++;
			else
				p2--;
		}
	}
	cout << a[p2].data - a[p1].data;
	fclose(stdin);
	return 0;
}
