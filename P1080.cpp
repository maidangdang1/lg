#include <iostream>
#include <algorithm>
#include <queue>

typedef unsigned long long ull;

using namespace std;

struct node
{
	int l;
	int r;
};

priority_queue <int> q;

void clr()
{
	while (!q.empty())
		q.pop();
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int c[n];
	int i;
	ull 
	node num[n + 10];
	for (i = 1;i <= n;i++)
		cin >> num[i].l >> num[i].r;
	for (i = 0;i < n;i++)
		c[i] = i + 1;
	clr();
	int left = a;
	//int right = b;
	priority_queue <int, vector<int>, greater<int> > ans;
	q.push(left / num[1].r);
	for (i = 2;i <= n;i++)
	{
		left *= num[i - 1].l;
		//right *= num[i].r;
		q.push(left / num[i].r);
	}
	ans.push(q.top());
	while (next_permutation(c, c + n))
	{
		clr();
		left = a;
		//int right = b;
		q.push(left / num[c[0]].r);
		for (i = 1;i < n;i++)
		{
			left *= num[c[i - 1]].l;
			//right *= num[c[i - 1]].r;
			q.push(left / num[c[i]].r);
		}
		ans.push(q.top());
	}
	cout << ans.top();
	fclose(stdin);
	return 0;
}
