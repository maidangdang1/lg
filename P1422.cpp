#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	double sum;
	if (n <= 150)
		sum = n * 0.4463;
	else if (n <= 400)
		sum = 0.4663 * n - 3;
	else
		sum = 0.5663 * n - 43;
	cout << setprecision(1) << fixed << sum;
	fclose(stdin);
	return 0;
}
