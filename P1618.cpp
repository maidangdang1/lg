#include <iostream>

using namespace std;

bool used[10];
int p[20];
int a, b, c;
bool pd;

int mix(int sta)
{
	int ans = 0;
	int i;
	for (i = 0;i < 3;i++)
		ans = ans * 10 + p[sta + i];
	return ans;
}

void per(int floor)
{
	int x, y, z;
	if (floor == 10)
	{
		x = mix(1);
		y = mix(4);
		z = mix(7);
		if (x * b == y * a && x * c == z * a && y * c == z * b)
		{
			pd = true;
			cout << x << " " << y << " " << z << endl;
		}
		return;
	}
	int i;
	for (i = 1;i <= 9;i++)
	{
		if (used[i] == false)
		{
			used[i] = true;
			p[floor] = i;
			per(floor + 1);
			used[i] = false;
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	//int a, b, c;
	cin >> a >> b >> c;
	per(1);
	if (pd == false)
		cout << "No!!!";
	fclose(stdin);
	return 0;
}
