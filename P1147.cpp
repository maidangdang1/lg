#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int m;
	cin >> m;
	int qzh[m + 10];
	memset(qzh, 0, sizeof(qzh));
	int i;
	for (i = 1;i <= m;i++)
		qzh[i] = qzh[i - 1] + i;
	int tp1 = 0;
	int tp2 = 0;
	while (tp1 < m && tp2 < m)
	{
		if (qzh[tp2] - qzh[tp1] + tp1 < m)
			tp2++;
		else if (qzh[tp2] - qzh[tp1] + tp1 > m)
			tp1++;
		else
		{
			cout << tp1 << " " << tp2 << endl;
			tp1++;
		}
	}
	fclose(stdin);
	return 0;
}
