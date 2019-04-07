#include <iostream>
#include <cmath>
using namespace std;
bool pd = false;
void cifang(int n)
{
	int i;
	//bool pd = false;
	while (n > 0)
	{
		for (i = 0;; i++)
		{
			if (pow(2, i) > n)
				break;
		}
		i--;
		n = n - pow(2, i);
		if (pd)
			cout << "+";
		if (i != 2 && i != 0)
		{
			if (i == 1)
			{
				cout << "2";
				pd = true;
				cifang(n);
			}
			else
			{
				cout << "2(";
				cifang(i);
				cout << ")";
			}
		}
		else
		{
			cout << "2(" << i << ")";
		}
		pd = true;
		cifang(n);
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	cifang(n);
	fclose(stdin);
	return 0;
}
