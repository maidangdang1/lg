#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a * 0.2 + b * 0.3 + c * 0.5;
	cout << sum;
	fclose(stdin);
	return 0;
}