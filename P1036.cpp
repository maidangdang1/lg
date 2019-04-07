#include <iostream>

using namespace std;

int n, k;
int x[30];
bool vis[30];
int cnt;

bool prime(int num)
{
	int i;
	for (i = 2;i * i <= num;i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void dfs(int floor, int sta)
{
	int i;
	int temp;
	if (floor == k + 1)
	{
		temp = 0;
		for (i = 1;i <= n;i++)
		{
			if (vis[i])
				temp += x[i];
		}
		if (prime(temp))
			cnt++;
		return;
	}
	else
	{
		for (i = sta;i <= n;i++)
		{
			if (vis[i] == false)
			{
				vis[i] = true;
				dfs(floor + 1, i);
				vis[i] = false;
			}
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n >> k;
	int i;
	for (i = 1;i <= n;i++)
		cin >> x[i];
	dfs(1, 1);
	cout << cnt;
	fclose(stdin);
	return 0;
}
