#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	freopen("test.txt", "r", stdin);
	string k;
	cin >> k;
	string s;
	cin >> s;
	int len = k.length();
	int a[len + 10];
	int i;
	for (i = 0;i < len;i++)
	{
		if (k[i] < 93)
		{
			a[i] = k[i];
			a[i] -= 'A';
		}
		else
		{
			a[i] = k[i];
			a[i] -= 'a';
		}
	}
	len = s.length();
	int cnt = 0;
	for (i = 0;i < len;i++)
	{
		if (s[i] > 93)
		{
			s[i] -= a[cnt];
			if (s[i] < 'a')
				s[i] += 26;
		}
		else
		{
			s[i] -= a[cnt];
			if (s[i] < 'A')
				s[i] += 26;
		}
		cnt++;
		if (cnt >= k.length())
			cnt = 0;
	}
	for (i = 0;i < len;i++)
		cout << s[i];
	fclose(stdin);
	return 0;
}
