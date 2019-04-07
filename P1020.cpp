#include <iostream>
using namespace std;
struct node
{
	int data = 0;
	int down = 0;
	int up = 0;
};
int main()
{
	freopen("test.txt", "r", stdin);
	node a[100010];
	int i = 1;
	while (cin >> a[i].data)
		i++;
	i--;
	int n = i;
	int j;
	int temp;
	int upmax = 0;
	int downmax = 0;
	for (i = 1;i <= n;i++)
	{
		temp = 0;
		for (j = i;j >= 0;j--)
		{
			if (a[j].data >= a[i].data && a[j].down > temp)
				temp = a[j].down;
		}
		a[i].down = temp + 1;
		if (a[i].down > downmax)
			downmax = a[i].down;
		temp = 0;
		for (j = i;j >= 0;j--)
		{
			if (a[j].data < a[i].data && a[j].up > temp)
				temp = a[j].up;
		}
		a[i].up = temp + 1;
		if (a[i].up > upmax)
			upmax = a[i].up;
	}
	cout << downmax << endl << upmax;
	fclose(stdin);
	return 0;
}
