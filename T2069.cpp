#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int temp;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int lcm(int a, int b)
{
	int temp_lcm;
	temp_lcm = a * b / gcd(a, b);//最小公倍数等于两数之积除以其最大公约数
	return temp_lcm;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int i;
	int j;
	int cnt = 0;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (lcm(i, j) == n)
				cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
