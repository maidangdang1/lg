#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int x;
	int y;
	int z;
};
bool comp(node x,node y)
{
	return x.z < y.z;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	node a[n + 10];
	int i;
	for (i = 1;i <= n;i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	sort(a + 1, a + 1 + n, comp);
	long double cnt = 0.00000;
	for (i = 2;i <= n;i++)
		cnt += sqrt(pow(a[i].x - a[i - 1].x, 2) + pow(a[i].y - a[i - 1].y, 2) + pow(a[i].z - a[i - 1].z, 2));
	cout << setprecision(3) << fixed << cnt;
	fclose(stdin);
	return 0;
}
