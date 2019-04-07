#include <iostream>
using namespace std;
struct node
{
	int in;
	int out;
	int sum;
};
int main()
{
	freopen("test.txt", "r", stdin);
	int a, n, m, x;
	cin >> a >> n >> m >> x;
	node b[n + 1];
	b[1].in = b[1].sum = a;
	b[1].out = 0;
	b[n].out = m;
	int i;
	int c;
	int j;
	for (i = 0;;i++)
	{
		b[2].in = b[2].out = i;
		b[2].sum = b[1].sum + b[2].in - b[2].out;
		for (j = 3;j < n;j++)
		{
			b[j].in = b[j - 1].in + b[j - 2].in;
			b[j].out = b[j - 1].in;
			b[j].sum = b[j - 1].sum + b[j].in - b[j].out;
		}
		if (b[n - 1].sum == b[n].out)
			break;
	}
	cout << b[x].sum;
	return 0;
}
