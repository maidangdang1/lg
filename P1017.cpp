#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
int jinzhi(int n, int base)
{
	int i;
	int ysh;
	if (n > 0)
	{
		for (i = 0;i >= -16385;i--)
		{
			if (base * i > n)
			{
				i++;
				ysh = n - base * i;
				return ysh;
			}
		}
	}
	else
	{
		for (i = 0;i <= 16385;i++)
		{
			if (base * i <= n)
			{
				ysh = n - base * i;
				return ysh;
			}
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int base;
	cin >> base;
	cout << n << "=";
	int a[101];
	int i = 0;
	memset(a, 0, sizeof(a));
	while (n != 0)
	{
		a[i] = jinzhi(n, base);
		if (n < 0 && a[i] != 0)
			n = n / base + 1;
		else
			n = n / base;
		i++;
	}
	i--;
	for (i;i >= 0;i--)
	{
		if (a[i] >= 10)
			cout << (char)(a[i] + 55);
		else
			cout << a[i];
	}
	cout << "(base" << base << ")";
	fclose(stdin);
	return 0;
}
