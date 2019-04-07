#include <iostream>
using namespace std;
int main()
{
	//freopen("test.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	int num = 1;
	int 
	int temp;
	int sum = 0;
	int times;
	while (n > 0)
	{
		mid = n / 2;
		times = mid / k;
		temp = mid % k;
		if (temp)
			times++
		sum += times * num;
		n -= times * k;
		num *= 2;
	}
	cout << sum;
	//fclose(stdin);
	return 0;
}
