#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	int h[n + 10];
	h[0] = 0;
	int i;
	for (i = 1;i <= n;i++)
		cin >> h[i];
	ll cnt = 0;
	sort(h + 1, h + 1 + n);
	int j;
	i = 0;
	j = n + 1;
	while (j - 1 > i)
	{
		j--;
		cnt += pow(h[j] - h[i], 2);
		i++;
		cnt += pow(h[j] - h[i], 2);
	}
	/*
	if (n % 2 == 1)
		cnt -= pow(h[i] - h[i - 1], 2);
	*/
	cout << cnt;
	fclose(stdin);
	return 0;
}
