#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1001];

void qsort(int start, int end)
{
	int i = start;
	int j = end;
	int base = a[(start + end) / 2];
	while (i <= j)
	{
		while (a[j] > base)
			j--;
		while (a[i] < base)
			i++;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < end)
		qsort(i, end);
	if (j > start)
		qsort(start, j);
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	int i;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	//sort(a + 1, a + 1 + n);
	qsort(1, n);
	double wei;
	int num;
	int pd = false;
	int j;
	int mo;
	for (i = 1; i <= q; i++)
	{
		cin >> wei >> num;
		mo = pow(10, wei);
		for (j = 1; j <= n; j++)
		{
			if (a[j] % mo == num)
			{
				cout << a[j] << endl;
				pd = true;
				break;
			}
		}
		if (pd == false)
			cout << "-1" << endl;
		pd = false;
	}
	fclose(stdin);
	return 0;
}
