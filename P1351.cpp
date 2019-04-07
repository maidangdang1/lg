#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	bool edge[n + 10][n + 10];
	short w[n + 10];
	memset(edge, false, sizeof(edge));
	int i;
	int temp;
	int temp1, temp2;
	for (i = 1;i < n;i++)
	{
		cin >> temp1 >> temp2;
		edge[temp1][temp2] = edge[temp2][temp1] = true;
	}
	for (i = 1;i <= n;i++)
		cin >> w[i];
	int cnt = 0;
	int j;
	queue <int> q1;
	queue <int> q2;
	set <int> s;
	int k;
	int maxi = 0;
	int len;
	for (i = 1;i <= n;i++)
	{
		q1 = queue <int>();
		q2 = queue <int>();
		for (j = 1;j <= n;j++)
		{
			if (edge[i][j])
				q1.push(j);
		}
		len = q1.size();
		for (j = 1;j <= len;j++)
		{
			temp = q1.front();
			q1.pop();
			for (k = 1;k <= n;k++)
			{
				if (edge[temp][k] && k != i)
					q2.push(k);
			}
		}
		len = q2.size();
		for (j = 1;j <= len;j++)
		{
			temp = q2.front();
			q2.pop();
			if (w[temp] * w[i] > maxi)
				maxi = w[temp] * w[i];
			cnt += w[temp] * w[i];
			cnt = cnt % 10007;
		}
	}
	cout << maxi << " " << cnt;
	fclose(stdin);
	return 0;
}
