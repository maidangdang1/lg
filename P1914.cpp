#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = s.length();
	int i;
	char temp;
	for (i = 0;i < len;i++)
	{
		temp = s[i];
		if (temp + n > 'z')
			temp -= 26;
		temp += n;
		cout << temp;
	}
	fclose(stdin);
	return 0;
}
