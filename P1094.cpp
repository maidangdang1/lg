#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int max;
	int n;
	cin >> max >> n;
	int i;
	int a[n + 1];
	for (i = 1;i <= n;i++)
		cin >> a[i];
	int j = n;
	int sum = 0;
	sort(a + 1, a + 1 + n);
	for (i = 1;i <= j;i++)
	{
		for (j;j >= i;j--)
		{
			if (a[i] + a[j] <= max)
			{
				sum++;
				i++;
			}
			else
				sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	return 0;
}
