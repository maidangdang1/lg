#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct node
{
	int u;
	int v;
};
int main()
{
	freopen("test.txt","r", stdin);
	int m, t;
	cin >> t >> m;
	node a[m + 10];
	int i;
	for (i = 1;i <= m;i++)
	cin >> a[i].u >> a[i].v;
	int bag[t + 10];
	memset(bag, 0, sizeof(bag));
	int j;
	for (i = 1;i <= m;i++)
	{
		for (j = t;j >= 1;j--)
		{
			if (j < a[i].u)
				continue;
			else
				bag[j] = max(bag[j], bag[j - a[i].u] + a[i].v);
		}
	}
	cout << bag[t];
	fclose(stdin);
	return 0;
}
