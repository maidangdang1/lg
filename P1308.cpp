#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string s;
string temp;

void mystrlwr1()
{
	int len = s.length();
	for (int i = 0;i < len;i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
}
void mystrlwr2()
{
	int len = temp.length();
	for (int i = 0;i < len;i++)
	{
		if (temp[i] >= 'A' && temp[i] <= 'Z')
			temp[i] += 32;
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> s;
	mystrlwr1();
	//vector <string> ss;
	//vector <int> len;
	int i;
	int cnt = 0;
	int f = 0;
	int fnum = 0;
	bool pd = false;
	while(cin >> temp)
	{
		mystrlwr2();
		if (temp == s)
		{
			if (pd == false)
			{
				fnum = cnt;
				pd = true;
			}
			f++;
		}
		i = temp.length();
		cnt += i;
		cnt++;
		/*
		i = temp.length();
		ss.push_back(temp);
		len.push_back(i);
		*/
	}
	if (pd)
		cout << f << " " << fnum;
	else
		cout << -1;
	fclose(stdin);
	return 0;
}
