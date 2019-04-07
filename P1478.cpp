#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int height;
	int si;
};

bool comp(node x, node y)
{
	return x.si < y.si;
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, s;
	cin >> n >> s;
	int a, b;
	cin >> a >> b;
	int i;
	node data[n + 10];
	for (i = 1;i <= n;i++)
		cin >> data[i].height >> data[i].si;
	sort(data + 1, data + 1 + n, comp);
	int cnt = 0;
	for (i = 1;i <= n;i++)
	{
		if (data[i].si <= s && data[i].height <= a + b)
		{
			cnt ++;
			s -= data[i].si;
		}
	}
	cout << cnt;
	fclose(stdin);
	return 0;
}
