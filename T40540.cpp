#include <iostream>
using namespace std;
void change(int n)
{
	int cou = 0;
	int a[105];
	while (n > 0)
	{
		cou++;
		a[cou] = n % 2;
		n /= 2;
	}
	while (cou >= 1)
	{
		cout << a[cou];
		cou--;
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	int a, b;
	cin >> a >> b;
	int c = a + b;
	change(a);
	cout << "+";
	change(b);
	cout << "=";
	change(c);
	fclose(stdin);
	return 0;
}