#include <iostream>
using namespace std;
struct node
{
	int in = 0;
	int to;
	int w;
	bool vis = false;
};
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	node a[n + 10];
	int i;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i].to >> a[i].w;
		a[a[i].to].in++;
	}
	bool change = true;
	do
	{
		change = false;
		for (i = 1;i <= n;i++)
		{
			if (a[i].in == 0 && a[i].vis == false)
			{
				a[a[i].to].in--;
				a[i].vis = true;
				change = true;
			}
		}
	}
	while (change);
	int temp;
	int cnt = 0;
	int j;
	for (i = 1;i <= n;i++)
	{
		j = i;
		temp = 0;
		while (a[j].vis == false)
		{
			temp += a[j].w;
			a[j].vis = true;
			j = a[j].to;
		}
		if (temp > cnt)
			cnt = temp;
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
