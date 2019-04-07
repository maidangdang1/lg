#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	freopen("test.txt", "r", stdin);
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;
	int i;
	int len = s.length();
	int temp1 = 0;
	int temp = 0;
	int j;
	int k;
	char a;
	int l;
	for (i = 0;i < len;i++)
	{
		if (s[i] == '-')
		{
			temp1 = i;
			for (j = temp;j < temp1;j++)
				cout << s[j];
			temp = i + 1;
			if (s[i - 1] >= s[i + 1] || (s[i - 1] < 58 && s[i + 1] > 96) || i == 0 || i == len - 1 || s[i - 1] == '-' || s[i + 1] == '-')
			{
				cout << "-";
				continue;
			}
			if (s[i - 1] + 1 == s[i + 1])
				continue;
			k = s[i + 1] - s[i - 1] - 1;
			if (p3 == 1)
			{
				a = s[i - 1];
				a++;
				if (p1 == 2 && a > 96)
					a -= 32;
				while (k--)
				{
					for (l = 1;l <= p2;l++)
					{
						if (p1 == 3)
							cout << "*";
						else
							cout << a;
					}
					a++;
				}
			}
			if (p3 == 2)
			{
				a = s[i + 1];
				a--;
				if (p1 == 2 && a > 96)
					a -= 32;
				while (k--)
				{
					for (l = 1;l <= p2;l++)
					{
						if (p1 == 3)
							cout << "*";
						else
							cout << a;
					}
					a--;
				}
			}
		}
	}
	for (j = temp;j < len;j++)
		cout << s[j];
	fclose(stdin);
	return 0;
}
