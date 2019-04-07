#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	string name;
	int score1;
	int score2;
	bool ganbu = false;
	bool xibu = false;
	int lunwen;
	int sum = 0;
};
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	node a[n];
	int i;
	char temp;
	int num;
	int max = 0;
	int sum = 0;
	for (i = 0;i < n;i++)
	{
		cin >> a[i].name >> a[i].score1 >> a[i].score2;
		cin >> temp;
		if (temp == 'Y')
			a[i].ganbu = true;
		cin >> temp;
		if (temp == 'Y')
			a[i].xibu = true;
		cin >> a[i].lunwen;
	}
	for (i = 0;i < n;i++)
	{
		if (a[i].score1 > 80 && a[i].lunwen > 0)
			a[i].sum += 8000;
		if (a[i].score1 > 85 && a[i].score2 > 80)
			a[i].sum += 4000;
		if (a[i].score1 > 90)
			a[i].sum += 2000;
		if (a[i].score1 > 85 && a[i].xibu)
			a[i].sum += 1000;
		if (a[i].score2 > 80 && a[i].ganbu)
			a[i].sum += 850;
	}
	for (i = 0;i < n;i++)
	{
		sum += a[i].sum;
		if (a[i].sum > max)
		{
			num = i;
			max = a[i].sum;
		}
	}
	cout << a[num].name << endl << a[num].sum << endl << sum;
	fclose(stdin);
	return 0;
}
