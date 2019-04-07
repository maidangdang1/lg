#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
	unsigned int v;
	unsigned int w;
	unsigned int times;
};
bool comp(node x1, node x2)
{
	return x1.v < x2.v;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int limit;
	cin >> limit;
	int n;
	cin >> n;
	unsigned int a[limit + 1];
	memset(a, 0, sizeof(a));
	node b[n + 1];
	int i;
	for (i = 1;i <= n;i++)
	{
		cin >> b[i].v >> b[i].w;
		b[i].times = b[i].v * b[i].w;
	}
	//sort(b, b + n, comp);
	int temp;
	int j;
	for (i = 1;i <= n;i++)
	{
		for (j = limit;j >= b[i].v;j--)
			a[j] = max(a[j], a[j - b[i].v] + b[i].times);
	}
	cout << a[limit];
	fclose(stdin);
	return 0;
}
