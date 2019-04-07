#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int n, h, r;
	while (t--)
	{
		cin >> n >> h >> r;
		if (r * 2 * n < h)
		{
			cout << "No" << endl;
			continue;
		}
	}
}
