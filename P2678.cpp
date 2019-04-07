#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	int data;
	bool pd = false;
};
int main()
{
	freopen("test.txt", "r", stdin);
	int l ,n, m;
	cin >> l >> n >> m;
	node stone[n + 10];
	stone[0].data = 0;
	int i;
	queue <int> temp1;
	for (i = 1;i <= n;i++)
		cin >> stone[i].data;
	stone[n + 1].data = l;
	priority_queue <int, vector<int>, greater<int> > cf;
	for (i = 1;i <= n + 1;i++)
		cf.push(stone[i].data - stone[i - 1].data);
	int ans;
	int left = 0;
	int right = l;
	int p1;
	int p2;
	int num;
	bool find;
	int temp;
	int cnt;
	while (right - 1 > left)
	{
		cnt = 0;
		find = false;
		ans = (left + right) >> 1;
		while (cnt <= m)
		{
			temp = cf.top();
			for (i = 1;i <= n;i++)
			{
				if (stone[i].data - stone[i - 1].data == temp && stone[i].pd == false)
				{
					stone[i].pd = true;
					temp = stone[i + 1].data - stone[i - 1].data;
					cnt++;
					temp1.push(i);
					break;
				}
			}
			cf.push(temp);
			if (cf.top() <= ans)
			{
				find = true;
				break;
			}
		}
		if (find)
			right = ans;
		else
			left = ans;
		while (temp1.empty() == false)
		{
			temp = temp1.front();
			stone[i].pd = false;
			temp1.pop();
		}
	}
	cout << cf.top();
	fclose(stdin);
	return 0;
}
