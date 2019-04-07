#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int x1, y1, z1, x2, y2, z2, x, y, z;
	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)
	{
		x = y1 * z2 - y2 * z1;
		y = z1 * x2 - z2 * x1;
		z = x1 * y2 - x2 * y1;
		z /= x;
		y /= x;
		x = 1;
		cout << x << " " << y << " " << z << endl;
	}
	fclose(stdin);
	return 0;
}
