#include <iostream>
#include <stack>
#include <cmath>
typedef long long ll;
using namespace std;
int a[11];
int times = 0;
stack <int> b;
void fenlei(char x)
{
	a[times] = x - 48;
	times++;
}
void ruzhan()
{
	int sum = 0;
	int i = 0;
	times--;
	while (times >= 0)
	{
		sum += pow(10, times) * a[i];
		i++;
	}
	b.push(sum);
}
void calc(char x)
{
	int temp1, temp2;
	int sum;
	temp1 = b.top();
	b.pop();
	temp2 = b.top();
	b.pop();
	if (x == 43)
	{
		sum = temp2 + temp1;
		b.push(sum);
	}
	else if (x == 45)
	{
		sum = temp2 - temp1;
		b.push(sum);
	}
	else if (x == 42)
	{
		sum = temp2 * temp1;
		b.push(sum);
	}
	else
	{
		sum = temp2 / temp1;
		b.push(sum);
	}
}
int main()
{
	char temp[1010];
	ll sum = 0;
	int i = 0;
	gets(temp);
	for (i = 0;;i++)
	{
		if (temp[i] == 64)
			break;
		if (temp[i] == 46)
		{
			ruzhan();
			times = 0;
			continue;
		}
		if (temp[i] >= 48 && temp[i] <= 57)
			fenlei(temp[i]);
		if (temp[i] == 43 || temp[i] == 45 || temp[i] == 42 || temp[i] == 47)
			calc(temp[i]);
	}
	cout << b.top();
	return 0;
}