#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int m;
	cin >> m;
	int a[10];
	a[1] = 1;
	a[2] = 1;
	int cnt = 1;
	//bool pd = true;
	while (1)
	{
		if (a[1] == 0 && a[2] == 1)
		{
			cout << cnt;
			fclose(stdin);
			return 0;
		}
		else
		{
			a[3] = (a[2] + a[1]) % m;
			a[1] = a[2];
			a[2] = a[3];
			cnt++;
		}
	}
}
