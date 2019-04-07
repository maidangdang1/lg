#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int a[n + 1];
	int i;
	int sum = 0;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int num = 0;
	int ave = sum / n;
	int start = 1;
	int end = 1;
	for (i = 1;i < n;i++)
	{
		if (a[i] < ave)
		{
			a[i + 1] -= (ave - a[i]);
			a[i] = ave;
			num++;
		}
		else if (a[i] > ave)
		{
			a[i + 1] += (a[i] - ave);
			a[i] = ave;
			num++;
		}
	}
	cout << num;
	fclose(stdin);
	return 0;
}
