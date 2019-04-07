#include <iostream>
using namespace std;
long long l;
char a[10010][10010];
int shuzhi(int x, int y)
{
	if (y == 1 || y == l)
		return 1;
	//cout << 0 << " ";
	int shang = y;
	int xia = y;
	int sum = 1;
	while (shang > 0 && xia < l)
	{
		shang--;
		xia++;
		//cout << a[shang] << a[xia];
		if (a[x][shang] == a[x][xia])
			sum += 2;
	}
	return sum;
}
int shuiping(int x, int y)
{
	if (x == 1 || x == l)
		return 1;
	//cout << 0 << " ";
	int zuo = x;
	int you = x;
	int sum = 1;
	while (zuo > 0 && you < l)
	{
		zuo--;
		you++;
		//cout << a[zuo] << a[you];
		if (a[zuo][y] == a[you][y])
			sum += 2;
	}
	return sum;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int times;
	cin >> l >> times;
	int i;
	int j;
	int len1;
	int len2;
	int x, y;
	for (i = 1;i <= l;i++)
	{
		for (j = 1;j <= l;j++)
			cin >> a[i][j];
	}
	//cout << a[1][1] << " " << a[1][2] << " " << a[1][3] << " " << a[2][3] << " " << a[3][3] << endl;
	for (i = 1;i <= times;i++)
	{
		cin >> x >> y;
		len1 = shuzhi(x, y);
		len2 = shuiping(x, y);
		cout << max(len1, len2) << endl;
	}
	fclose(stdin);
	return 0;
}