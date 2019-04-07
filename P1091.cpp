#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int t[110];
int f(int l, int r, bool up)
{
	int book[110];
	memset(book, 0, sizeof(book));
	book[l] = 1;
	int m = 0;
	int i;
	int j;
	int big;
	int small;
	if (up)
	{
		for (i = l + 1;i <= r;i++)
		{
			big = 0;
			for (j = i;j >= l;j--)
			{
				if (t[j] < t[i] && book[j] > big)
					big = book[j];
			}
			book[i] = big + 1;
		}
	}
	else
	{
		for (i = l + 1;i <= r;i++)
		{
			small = 0;
			for (j = i;j >= l;j--)
			{
				if (t[j] > t[i] && book[j] > small)
					small = book[j];
			}
			book[i] = small + 1;
		}
	}
	for (i = l;i <= r;i++)
	{
		if (book[i] > m)
			m = book[i];
	}
	return r - l + 1 - m;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int i;
	int cnt = 666;
	int temp;
	//int t[n + 10];
	for (i = 1;i <= n;i++)
		cin >> t[i];
	for (i = 1;i <= n;i++)
	{
		temp = f(1, i, true) + f(i, n, false);
		if (temp < cnt)
			cnt = temp;
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
