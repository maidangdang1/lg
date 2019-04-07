#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct node
{
	int num[110];
	int weight;
	bool wrong = false;
};
node a[110];
int w[110];
void check(int w)
{
	
}
void find()
{
	int cnt;
	
}
int main()
{
	int n;
	cin >> n;
	int i;
	int m;
	int j;
	for (i = 1;i <= n + 1;i++)
	{
		cin >> m;
		for (j = 1;j <= m;j++)
			cin >> a[i].num[j];
		cin >> a[i].weight;
	}
	/*
	for (i = 1;i <= n + 1;i++)
	{
		a[i].wrong = true;
		dfs();
		;
		a[i].wrong = false;
	}
	*/
	find();
}
