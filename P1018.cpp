#include <iostream>
#include <cstring>
#include <string>

typedef unsigned long long ull;

using namespace std;

int n, k;
string s;
int len;
bool times[50];
ull keep[50];
ull temp;
ull maxi;
int cnt;

void change(int l, int r)
{
	temp = 0;
	for (l;l < r;l++)
		temp = temp * 10 + (s[l] - '0');
	keep[cnt] = temp;
	cnt++;
}

void dfs(int floor, int sta)
{
	int i;
	int l, r;
	if (floor == k + 1)
	{
		l = 0;
		r = 0;
		for (i = 1;i < len;i++)
		{
			if (times[i])
			{
				change(l, i);
				l = i;
			}
		}
		change(l, len);
		temp = 1;
		for (i = 0;i < cnt;i++)
			temp *= keep[i];
		if (temp > maxi)
			maxi = temp;
		cnt = 0;
	}
	else
	{
		for (i = sta;i < len;i++)
		{
			if (times[i] == false)
			{
				times[i] = true;
				dfs(floor + 1, i + 1);
				times[i] = false;
			}
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	//int n, k;
	cin >> n >> k;
	//string s;
	cin >> s;
	len = s.length();
	dfs(1, 1);
	cout << maxi;
	fclose(stdin);
	return 0;
}
