#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int a[n + 1];
	int i;
	for (i = 1;i <= n;i++)
		cin >> a[i];
	int left = 1;
	int right = n;
	bool pd = true;
	while (left != right)
	{
		if (pd)
		{
			if (a[left] > a[right])
				left++;
			else
				right--;
		}
		else
		{
			if (a[left] < a[right])
				left++;
			else
				right--;
		}
		pd = 1 - pd;
	}
	cout << a[left];
	fclose(stdin);
	return 0;
}