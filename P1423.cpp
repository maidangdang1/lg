#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	double n;
	cin >> n;
	int i = 1;
	double sum = 2.0;
	double a = 2.0;
	while (sum < n)
	{
		a *= 0.98;
		sum += a;
		i++;
	}
	cout << i;
	return 0;
}
