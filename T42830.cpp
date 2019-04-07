#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool isodd[5010];
int b[5010];
//int c[5010];
bool pri[5010];
bool prime(int n)
{
	int i;
	for (i = 2;i * i <= n;i++)
	{
		if (n % i == 0)
			return true;
	}
	return false;
}
bool num(int x)
{
	int i;
	int sum = 0;
	for (i = 2;i < x;i++)
	{
		if (x % i == 0)
			sum++;
	}
	if (sum % 2 == 1)
		return true;
	else
		return false;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int t;
	cin >> t;
	int i;
	memset(isodd, false, sizeof(isodd));
	memset(pri, true, sizeof(pri));
	for (i = 2;i <= 5000;i++)
		isodd[i] = prime(i);
	for (i = 2;i <= 5000;i += 2)
		isodd[i] = false;
	for (i = 2;i < 5000;i++)
		pri[i] = prime(i);
	for (i = 2;i < 5000;i++)
	{
		if (isodd[i] == false)
			continue;
		else
		{
			isodd[i] = num(i);
		}
	}
	/*
	for (i = 2;i <= 10;i++)
		cout << isodd[i] << " ";
	*/
	isodd[0] = false;
	isodd[1] = true;
	b[0] = 0;
	int temp;
	int A, B;
	for (i = 1;i <= 5000;i++)
		b[i] = b[i - 1] + isodd[i];
	for (i = 1;i <= t;i++)
	{
		cin >> A >> B;
		temp = b[B] - b[A - 1];
		if (temp % 2 == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	fclose(stdin);
	return 0;
}