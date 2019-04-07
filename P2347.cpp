#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int a1, a2, a3, a4, a5, a6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	int num;
	bool pd = false;
	int sum = 0;
	int a[100000];
	int cou = 0;
	int o;
	for (int i = 0;i <= a1;i++)
	{
		for (int j = 0;j <= a2;j++)
		{
			for (int k = 0;k <= a3;k++)
			{
				for (int l = 0;l <= a4;l++)
				{
					for (int m = 0;m <= a5;m++)
					{
						for (int n = 0;n <= a6;n++)
						{
							num = 1 * i + 2 * j + 3 * k + 5 * l + 10 * m + 20 * n;
							for (o = 0;o <= cou;o++)
							{
								if (a[o] == num || num == 0)
								{
									pd = true;
									break;
								}
							}
							if (pd)
								pd = false;
							else
							{
								a[cou] = num;
								cou++;
								sum++;
								//break;
							}
						}
					}
				}
			}
		}
	}
	cout << "Total=" << sum;
	fclose(stdin);
	return 0;
}
