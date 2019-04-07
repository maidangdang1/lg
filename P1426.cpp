#include <iostream>

using namespace std;

double length[300];
double speed[300];

void init()
{
	speed[1] = 7.00;
	length[1] = 7.00;
	int i;
	for (i = 2;length[i - 1] <= 150;i++)
	{
		speed[i] = speed[i - 1] * 0.98;
		length[i] = length[i - 1] + speed[i];
	}
}

int main()
{
	int s, x;
	cin >> s >> x;
	init();
	int i;
	for (i = 0;i < 300;i++)
	{
		if (length[i] >= s - x)
		{
			if (length[i + 1] > s + x)
			{
				cout << "n";
				return 0;
			}
			else
			{
				cout << "y";
				return 0;
			}
		}
	}
	/*
	for (i = 1;i < 300;i++)
		cout << length[i] << endl;
	*/
}
