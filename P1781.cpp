#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	string data;
	int rank;
};
node a[21];
void comp(int start, int end)
{
	string max = a[1].data;
	int rank1 = 1;
	int i;
	int j;
	int len1 = max.length();
	int len2;
	for (i = 2;i <= end;i++)
	{
		len1 = max.length();
		len2 = a[i].data.length();
		if (len1 <= len2)
		{
			if (len1 < len2)
			{
				max = a[i].data;
				rank1 = i;
			}
			else
			{
				for (j = 0;j < len1;j++)
				{
					if (a[i].data.at(j) > max.at(j))
					{
						max = a[i].data;
						rank1 = i;
						break;
					}
					else if (a[i].data.at(j) < max.at(j))
						break;
				}
			}
		}
	}
	a[0].data = max;
	a[0].rank = rank1;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int i;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i].data;
		a[i].rank = i;
	}
	comp(1, n);
	cout << a[0].rank << endl << a[0].data;
	fclose(stdin);
	return 0;
}
