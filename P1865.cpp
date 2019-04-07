#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool prime[1000010];
int qzh[1000010];

void init()
{
	int i;
	int j;
	for (i = 2;i <= 1000000;i++)
	{
		qzh[i] = qzh[i - 1];
		if (prime[i])
		{
			qzh[i]++;
			for (j = 2 * i;j <= 1000000;j += i)
				prime[j] = false;
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int l, r;
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	init();
	while (n--)
	{
		cin >> l >> r;
		if (l < 1 || r > m)
			cout << "Crossing the line" << endl;
		else
			cout << qzh[r] - qzh[l - 1] << endl;
	}
	fclose(stdin);
	return 0;
}
