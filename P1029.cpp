#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
	freopen("test.txt", "r", stdin);
	int x0, y0;
	cin >> x0 >> y0;
	int p, q;
	int temp = x0 * y0;
	int cnt = 0;
	for (p = 1;p <= temp;p++)
	{
		if (temp % p)
			continue;
		else
		{
			q = temp / p;
			if (gcd(p, q) == x0 && temp / gcd(p, q) == y0)
				cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
