#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
void qsort(int start, int end)
{
	int base = a[(start + end) / 2];
	int i = start;
	int j = end;
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
	int n;
	cin >> n;
	int i;
	for (i = 1;i <= n;i++)
		cin >> a[i];
	qsort(1, n);
	for (i = 1;i <= n;i++)
		cout << a[i] << " ";
	fclose(stdin);
	return 0;
}
