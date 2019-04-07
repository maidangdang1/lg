#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool isline = true;
	int i;
	ll cnt = 0;
	for (i = 1;cnt < n;i++)
	{
		cnt += i;
		isline = !isline;
	}
	i--;
	int temp1;
	int temp2;
	if (isline)
	{
		temp1 = i;
		temp2 = 1;
		while (temp1 != 1 && cnt != n)
		{
			temp1--;
			temp2++;
			cnt--;
		}
	}
	else
	{
		temp2 = i;
		temp1 = 1;
		while (temp2 != 1 && cnt != n)
		{
			temp1++;
			temp2--;
			cnt--;
		}
	}
	cout << temp1 << "/" << temp2;
	return 0;
}
