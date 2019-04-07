#include <iostream>
using namespace std;
struct node
{
	int money;
	int num;
};
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	node a[4];
	int i;
	for (i = 1;i <= 3;i++)
		cin >> a[i].num >> a[i].money;
	int temp1, temp2;
	int min = 99999999;
	int sum;
	for (i = 1;i <= 3;i++)
	{
		temp1 = n / a[i].num;
		temp2 = n % a[i].num;
		if (temp2)
			temp1++;
		sum = temp1 * a[i].money;
		if (sum < min)
			min = sum;
	}
	cout << min;
	fclose(stdin);
	return 0;
}
