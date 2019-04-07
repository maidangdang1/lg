#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	ll a[n + 10];
	int i;
	memset(a, 0, sizeof(a));
	ll max = -23333333;
	ll temp = 0;
	for (i = 1;i <= n;i++)
	{
		if (temp < 0)
			temp = 0;
		cin >> a[i];
		temp += a[i];
		if (temp > max)
			max = temp;
	}
	/*
	for (i = 1;i <= n;i++)
	{

	}
	*/
	cout << max;
	fclose(stdin);
	return 0;
}