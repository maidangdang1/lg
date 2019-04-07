#include <iostream>
#include <cstring>

const int mod = 11;

using namespace std;

int main()
{
	freopen("test.txt", "r", stdin);
	string s;
	cin >> s;
	int len = s.length();
	int i;
	int temp;
	int cnt = 0;
	int num = 1;
	for (i = 0;i < len - 1;i++)
	{
		if (s[i] == '-')
			continue;
		else
		{
			cnt += (s[i] - '0') * num;
			num++;
		}
	}
	cnt %= mod;
	if (cnt == (s[len - 1] - '0') || (cnt == 10 && s[len - 1] == 'X'))
	{
		cout << "Right";
		fclose(stdin);
		return 0;
	}
	else
	{
		for (i = 0;i < len - 1;i++)
			cout << s[i];
		if (cnt == 10)
			cout << "X";
		else
			cout << cnt;
	}
	fclose(stdin);
	return 0;
}
