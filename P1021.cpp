#include <iostream>
#include <cstring>
#include <cstdio>
//#pragma GCC optimize("Ofast")

using namespace std;

int a[25];
int fin[25];
int n, k;
int maxi;
int bag[1000010];

int judge()
{
	int i;
	int j;
	//int bag[1000010];
	memset(bag, n + 1, sizeof(bag));
	for (j = 1;j <= k;j++)
		bag[a[j]] = 1;
	//bag[1] = 1;
	for (i = 1;i <= 1000000;i++)
	{
		if (bag[i] > n)
			break;
		//j = 0;
		for (j = 1;j <= k;j++)
		{
			//if (bag[i + a[j]] == 0)
			//	bag[i + a[j]] = bag[i] + 1;
			//else
				bag[i + a[j]] = min(bag[i + a[j]], bag[i] + 1);
		}
	}
	return i - 1;
}

void dfs(int floor, int nowm)
{
	int temp;
	if (floor == k + 1)
	{
		temp = judge();
		if (temp > maxi)
		{
			maxi = temp;
			for (temp = 1;temp <= k;temp++)
				fin[temp] = a[temp];
		}
		return;
	}
	int i;
 	for (i = a[floor - 1] + 1;i <= nowm;i++)
	{
		a[floor] = i;
		temp = judge();
		dfs(floor + 1, temp + 1);
		a[floor] = 0;
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	//int n, k;
	cin >> n >> k;
	//int a[25];
	a[1] = 1;
	dfs(2, n + 1);
	int i;
	for (i = 1;i <= k;i++)
		cout << fin[i] << " ";
	cout << endl;
	cout <<"MAX=" << maxi;
	fclose(stdin);
	return 0;
}
