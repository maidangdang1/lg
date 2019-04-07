#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool comp(string x, string y)
{
	return x + y > y + x;
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	string a[20];
	int i;
	for (i = 0;i < n;i++)
		cin >> a[i];
	sort(a, a + n, comp);
	for (i = 0;i < n;i++)
		cout << a[i];
	fclose(stdin);
	return 0;
}
