#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string s;
	int cnt = 0;
	while (cin >> s)
		cnt += s.length();
	cout << cnt;
	return 0;
}
