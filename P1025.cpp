#include <iostream>
using namespace std;
int pailie[10];
int n, k;
int cnt = 0;
void pl(int now, int rest)
{
	int line;
	if (now == k + 1 && rest != 0)
		return;
	if (now == k + 1 && rest == 0)
	{
		cnt++;
		return;
	}
	line = rest / (k - now + 1);
	int i;
	for (i = pailie[now - 1];i <= line;i++)
	{
		pailie[now] = i;
		rest -= i;
		pl(now + 1, rest);
		rest += i;
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n >> k;
	pailie[0] = 1;
	pl(1, n);
	cout << cnt;
	fclose(stdin);
	return 0;
}
