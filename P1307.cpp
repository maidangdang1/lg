#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s[0] == '-')
		cout << "-";
	int len = s.length();
	int i;
	bool fir = true;
	for (i = len - 1;i >= 0;i--)
	{
		if (s[i] == '0' && fir)
			continue;
		if (s[i] == '-')
			continue;
		cout << s[i];
		fir = false;
	}
	return 0;
}