#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	freopen("text.txt", "r", stdin);
	int n;
	cin >> n;
	priority_queue <int, vector<int>, greater<int> > a;
	int i;
	int opt;
	int temp;
	for (i = 1;i <= n;i++)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> temp;
			a.push(temp);
		}
		else if (opt == 2)
			cout << a.top() << endl;
		else
			a.pop();
	}
	fclose(stdin);
	return 0;
}
