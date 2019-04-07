#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct node
{
	int data;
	int rank1;
};
bool comp1(node x1, node x2)
{
	return x1.data < x2.data;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int i;
	node a[n];
	for (i = 0;i < n;i++)
		cin >> a[i].data;
	for (i = 0;i < n;i++)
		a[i].rank1 = i + 1;
	sort(a, a + n, comp1);
	for (i = 0;i < n;i++)
		cout << a[i].rank1 << " ";
	cout << endl;
	double sum = 0.0;
	double ave = 0.0;
	int j;
	for (i = 0;i < n;i++)
	{
		for (j = i - 1;j >= 0;j--)
			sum += a[j].data;
	}
	ave = sum / n;
	cout << setprecision(2) << fixed << ave;
	fclose(stdin);
	return 0;
}
