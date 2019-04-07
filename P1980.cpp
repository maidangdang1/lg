#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n, x;
	int temp;
	short wei;
	cin >> n >> x;
	int sum = 0;
	n++;
	while (n--)
	{
		temp = n;
		while (temp)
		{
			wei = temp % 10;
			temp /= 10;
			if (wei == x)
				sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	return 0;
}
