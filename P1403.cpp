#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;
int a[1000010];
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	//memset(a, 1, sizeof(a));
	a[1] = 1;
	int i;
	int j;
	ll cnt = 0;
	for (i = 2;i <= n;i++)
	{
		a[i] += 2;
		for (j = i + i;j <= n;j += i)
			a[j]++;
	}
	for (i = 1;i <= n;i++)
		cnt += a[i];
	cout << cnt;
	fclose(stdin);
	return 0;
}
