#include <iostream>
#include <iomanip>

using namespace std;

struct node
{
	double d;
	double p;
};

double table[16][16];
node oil[16];
double d1, c, d2, p;
int n;
double dis[10];
const double initnum = 9999.9999;

void init()
{
	int i;
	int j;
	for (i = 0;i <= n + 1;i++)
	{
		for (j = 0;j <= n + 1;j++)
			table[i][j] = initnum;
	}
	double temp = c * d2;
	for (i = 0;i <= n;i++)
	{
		for (j = i + 1;j <= n + 1;j++)
		{
			if (oil[j].d - oil[i].d < temp)
				table[i][j] = (oil[j].d - oil[i].d) / d2 * oil[i].p;
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	//double d1, c, d2, p, n;
	cin >> d1 >> c >> d2 >> p >> n;
	/*
	if (d1 / d2 > c)
	{
		cout << "No Solution";
		fclose(stdin);
		return 0;
	}
	*/
	/*
	if (n == 0)
	{
		if (d1 / d2 > c)
		{
			cout << "No Solution";
			fclose(stdin);
			return 0;
		}
		else
		{
			cout << d1 / d2 * p;
			fclose(stdin);
			return 0;
		}
	}
	*/
	int i;
	oil[0].p = p;
	for (i = 1;i <= n;i++)
		cin >> oil[i].d >> oil[i].p;
	oil[i].d = d1;
	init();
	i = 0;
	//double temp = d1 / d2;
	int j;
	int k;
	for (j = 1;j <= n;j++)
	{
		for (i = 0;i <= n;i++)
		{
			for (k = i + 1;k <= n + 1;k++)
			{
				if (j < i)
					continue;
				/*
				if (table[i][k] == 0 && table[i][j] != 0 && table[j][k] != 0)
					table[i][k] = table[i][j] + table[j][k];
				else if (table[i][k] != 0 && table[i][j] != 0 && table[j][k] != 0 && table[i][j] + table[j][k] < table[i][k])
					table[i][k] = table[i][j] + table[j][k];
				*/
				if (table[i][j] + table[j][k] < table[i][k])
					table[i][k] = table[i][j] + table[j][k];
			}
		}
		i = 0;
	}
	/*
	for (i = 0;i <= n + 1;i++)
	{
		for (j = 0;j <= n + 1;j++)
			cout << table[i][j] << "	";
		cout << endl;
	}
	*/
	if (table[0][n + 1] == initnum)
		cout << "No Solution";
	else
		cout << setprecision(2) << fixed << table[0][n + 1];
	fclose(stdin);
	return 0;
}
