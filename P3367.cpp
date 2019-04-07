#include <iostream>
using namespace std;
int fa[10010];
int find(int x)
{
	//int fa;
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int i;
	for (i = 1;i <= n;i++)
		fa[i] = i;
	int opt;
	int b, c;
	//int j;
	for (i = 1;i <= m;i++)
	{
		cin >> opt >> b >> c;
		if (opt == 1)
		{
			fa[find(b)] = find(c);
			/*
			for (j = 1;j <= n;j++)
			{
				if (fa[j] == j)
					continue;
				else
					find(j);
			}
			*/
		}
		else
		{
			if (find(b) == find(c))
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
	}
	fclose(stdin);
	return 0;
}