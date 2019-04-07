#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	int opt;
	string name;
};
int main()
{
	freopen("text.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	node a[n + 10];
	int opt1;
	int temp;
	int ans = 1;
	int i;
	for (i = 1;i <= n;i++)
		cin >> a[i].opt >> a[i].name;
	for (i = 1;i <= m;i++)
	{
		cin >> opt1 >> temp;
		if (opt1)
		{
			if (a[ans].opt)
				ans -= temp;
			else
				ans += temp;
		}
		else
		{
			if (a[ans].opt)
				ans += temp;
			else
				ans -= temp;
		}
		if (ans > n)
			ans -= n;
		if (ans < 1)
			ans += n;
	}
	cout << a[ans].name;
	fclose(stdin);
	return 0;
}
