#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	int max;
	cin >> n >> max;
	int i;
	int temp;
	int sum = 0;
	bool pd = false;
	int num = 0;
	for (i = 1;i <= n;i++)
	{
		cin >> temp;
		sum += temp;
		if (sum > max)
		{
			if (i == n)
			{
				num += 2;
				pd = true;
			}
			else
			{
				sum = temp;
				num++;
			}
		}
	}
	if (pd == false)
		num++;
	cout << num;
	fclose(stdin);
	return 0;
}
