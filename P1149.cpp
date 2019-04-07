#include <iostream>

using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int fenjie(int n)
{
	if (n == 0)
		return 6;
	int temp;
	int cnt = 0;
	while (n > 0)
	{
		temp = n % 10;
		cnt += num[temp];
		n /= 10;
	}
	return cnt;
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int a, b, c;
	int temp;
	int cnt = 0;
	//cout << num[0] << endl;
	for (a = 0;a <= 1111;a++)
	{
		for (b = 0;b <= 1111;b++)
		{
			temp = 0;
			c = a + b;
			temp += fenjie(a);
			temp += fenjie(b);
			temp += fenjie(c);
			if (temp == n - 4)
				cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
