#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int a[13];
	int i;
	for (i = 1;i <= 12;i++)
		cin >> a[i];
	int rest = 0;
	int bank = 0;
	for (i = 1;i <= 12;i++)
	{
		rest = rest + 300 - a[i];
		while (rest > 100)
		{
			rest -= 100;
			bank += 100;
		}
		if (rest < 0)
		{
			cout << "-" << i;
			return 0;
		}
	}
	rest = rest + 1.2 * bank;
	cout << rest;
	fclose(stdin);
	return 0;
}
