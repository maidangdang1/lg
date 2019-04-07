#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
string o;
int po(int l, int r)
{
	int sum = 0;
	int cnt = 0;
	int temp;
	int asc;
	while (r >= l)
	{
		asc = o.at(r) - 48;
		temp = asc * pow(10, cnt);
		sum += temp;
		r--;
		cnt++;
	}
	return sum;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int t;
	cin >> t;
	bool power = false;
	bool ab[26];
	bool contribution[26];
	int c = 1;
	int asc;
	memset(ab, true, sizeof(ab));
	memset(contribution, false, sizeof(contribution));
	int w = 0;
	char bl;
	char d;
	int times = 0;
	int max = 0;
	//char temp1;
	string d1, d2;
	char temp[50];
	bool err = false;
	stack <char> loop;
	while (t--)
	{
		int l;
		cin >> l >> o;
		if (o.length() >= 6)
		{
			if (o.length() == 6)
			{
				power = true;
				w = o.at(4) - 48;
			}
			else
				w = po(4, o.length() - 2);
		}
		while (l--)
		{
			if (err)
			{
				gets(temp);
				gets(temp);
				continue;
			}
			cout << w << endl;
			cin >> d;
			if (d == 'F')
			{
				cin >> bl;
				asc = bl - 97;
				//cout << bl << endl;
				if (ab[asc])
				{
					ab[asc] = false;
					loop.push(bl);
					//cout << loop.top();
				}
				else
				{
					cout << "ERR" << endl;
					err = true;
				}
				cin >> d1;
				cin >> d2;
				if (d2.length() == 1 && d2.at(0) == 'n')
				{
					times++;
					contribution[asc] = true;
				}
				if (times > max)
					max = times;
					//cout << max << endl;
			}
			else if (d == 'E')
			{
				bl = loop.top();
				asc = bl - 97;
				loop.pop();
				ab[asc] = true;
				if (contribution[asc])
					times--;
				contribution[asc] = false;
			}
		}
		if (loop.empty())
		{
			if (max == w)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (err == false)
			cout << "ERR" << endl;
		err = false;
		power = false;
		w = 0;
		max = 0;
		times = 0;
	}
	fclose(stdin);
	return 0;
}
