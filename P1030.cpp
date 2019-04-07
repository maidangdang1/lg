#include <iostream>
#include <cstring>
using namespace std;
void dfs(string zhong, string hou)
{
	int i;
	if (zhong.length() == 1)
	{
		cout << zhong;
		return;
	}
	int len = hou.length();
	cout << hou[len - 1];
	for (i = 0;i < len;i++)
	{
		if (zhong[i] == hou[len - 1])
			break;
	}
	/*
	cout << zhong.substr(0, i) << endl;
	cout << hou.substr(0, i) << endl;
	cout << zhong.substr(i + 1, len - 1 - i) << endl;
	cout << hou.substr(i, len - 1 - i) << endl;
	;
	*/
	if (i > 0)
		dfs(zhong.substr(0, i), hou.substr(0, i));
	if (i + 1 <= len - 1)
		dfs(zhong.substr(i + 1), hou.substr(i, len - 1 - i));
}
int main()
{
	freopen("test.txt", "r", stdin);
	string zhong;
	string hou;
	cin >> zhong >> hou;
	dfs(zhong, hou);
	fclose(stdin);
	return 0;
}
