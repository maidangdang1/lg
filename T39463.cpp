#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int i;
	int a[n + 10];
	a[0] = 0;
	//int cf[n + 10];
	//long long qzh[n + 10];
	//qzh[0] = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		//cf[i] -= cf[i - 1];
		//qzh[i] = qzh[i - 1] + a[i];
	}
	int sum = 0;
	int j;
	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (j - i == abs(a[j] - a[i]))
				sum++;
			if (a[j] + a[i] == j - i)
				sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	return 0;
}
