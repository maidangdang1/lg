#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[10001];
void guiwei(int num)
{
	while(a[num] > a[num + 1] && num < n)
	{
		swap(a[num], a[num + 1]);
		num++;
	}
	return;
}
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n;
	int i;
	int dui1;
	int dui2;
	unsigned long long sum = 0;
	for (i = 1;i <= n;i++)	
		cin >> a[i];
	int dui = a[1];
	sort(a + 1, a + 1 + n);
	for (i = 1;i < n;i++)
	{
		sum += a[i];
		sum += a[i + 1];
		a[i + 1] += a[i];
		a[i] = 0;
		guiwei(i + 1);
	}
	cout << sum;
	fclose(stdin);
	return 0;
}
