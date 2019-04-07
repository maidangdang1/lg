#include <iostream>
#define ll long long
using namespace std;
const int mod = 6662333;
int qpower(int n, ll power)
{
	if (power == 1)
		return n;
	else if (power % 2 == 1)
		return qpower(2, power / 2) % mod * qpower(2, power / 2) % mod * n % mod;
	else
		return qpower(2, power / 2) % mod * qpower(2, power / 2) % mod;
}
int main()
{
	freopen ("test.txt", "r", stdin);
	ll n;
	cin >> n;
	cout << qpower(2, n - 1);
	fclose(stdin);
	return 0;
}
