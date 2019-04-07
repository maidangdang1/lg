#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	queue <char> score11;
	queue <char> score21;
	char temp;
	while (cin >> temp)
	{
		if (temp == 'E')
			break;
		else
		{
			score11.push(temp);
			score21.push(temp);
		}
	}
	int l = 0;
	int r = 0;
	while (score11.empty() == false)
	{
		temp = score11.front();
		score11.pop();
		if (temp == 'W')
			l++;
		else
			r++;
		if ((l >= 11 || r >= 11) && abs(l - r) >= 2)
		{
			cout << l << ":" << r << endl;
			l = 0;
			r = 0;
		}
	}
	cout << l << ":" << r << endl;
	cout << endl;
	l = 0;
	r = 0;
	while (score21.empty() == false)
	{
		temp = score21.front();
		score21.pop();
		if (temp == 'W')
			l++;
		else
			r++;
		if ((l >= 21 || r >= 21) && abs(l - r) >= 2)
		{
			cout << l << ":" << r << endl;
			l = 0;
			r = 0;
		}
	}
	cout << l << ":" << r;
	fclose(stdin);
	return 0;
}
