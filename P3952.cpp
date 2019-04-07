#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	cin >> t;
	bool power = false;
	bool ab[26];
	int c = 1;
	memset(ab, true, sizeof(ab));
	int w;
	char bl;
	char d;
	stack <int> loop;
	while (t--)
	{
		int l;
		string o;
		cin >> l >> o;
		if (o.length() == 6)
		{
			power = true;
			w = o.at(4) - 48;
		}
		while (l--)
		{
			cin >> d;
			if (d == 'F')
			{
				loop.push(c);
				cin >> bl;
				if (ab[])
			}
		}
		power = false;
	}
	return 0;
}
