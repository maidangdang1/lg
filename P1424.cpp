#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int x;
	long long n, sum = 0;
	cin >> x >> n;
	int i;
	for (i = 0;i < n;i++)
	{
		if (x % 7 == 6 || x % 7 == 0)
		{
			x++;
			continue;
		}
		else
		{
			sum += 250;
			x++;
		}
	}
	cout << sum;
	return 0;
}
