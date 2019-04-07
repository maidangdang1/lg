#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
bool prime[10000010];
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	int n, m;
	cin >> n >> m;
	int i;
	int j;
	for (i = 2;i <= n;i++)
	{
		j = i;
		if (prime[i])
		{
			j += i;
			while (j <= n)
			{
				prime[j] = false;
				j += i;
			}
		}
	}
	int temp;
	for (i = 1;i <= m;i++)
	{
		cin >> temp;
		if (prime[temp])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	fclose(stdin);
	return 0;
}
