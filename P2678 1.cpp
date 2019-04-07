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
	int cnt = 0;
	int j;
	while (cnt < m)
	{
		temp = cf.top();
		cf.pop();
		for (i = 1;i <= n;i++)
		{
			if (stone[i].data - stone[i - 1].data == temp && stone[i].pd == false)
			{
				cnt++;
				temp = stone[i + 1].data - stone[i - 1].data;
				stone[i].pd = true;
				cf.push(temp);
				break;
			}
		}
	}
	cout << cf.top();
	fclose(stdin);
	return 0;
}
