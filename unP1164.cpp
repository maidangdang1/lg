#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int a[m + 1];
	memset(a, 0, sizeof(a));
	int i;
	int b[n + 1];
	for (i = 1;i <= n;i++)
		cin >> b[i];
	int j;
	int num = 0;
	for (i = 1;i <= n;i++)
	{
		a[m] = 0;
		for (j = m;j >= b[i];j--)
		{
			a[j] = max(a[j], a[j - b[i]] + b[i]);
		}
		if (a[m] == m)
			num++;
	}
	cout << num;
	fclose(stdin);
	return 0;
}
