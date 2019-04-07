#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	string sa, sb;
	cin >> sa >> sb;
	bool pd = false;
	int a[501];
	int b[501];
	int c[601];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	int lena = sa.length();
	int lenb = sb.length();
	int i;
	for(i = 0;i <= lena - 1;i++)
		a[lena - i - 1]=sa[i] - 48;
	for(i = 0;i <= lenb - 1;i++)
		b[lenb - i - 1]=sb[i] - 48;
	i = 0;
	while(i <= lena || i <= lenb)
	{
		c[i] = a[i] + b[i];
		i++;
	}
	i = 0;
	while(i < lena || i < lenb)
	{
		c[i + 1] = c[i + 1] + c[i] / 10;
		c[i] = c[i] % 10;
		i++;
	}
	while (c[i] != 0)
	{
		c[i + 1] = c[i + 1] + c[i] / 10;
		c[i] = c[i] % 10;
		i++;
		//pd = true;
	}
	i--;
	/*
	if (pd)
		i--;
	*/
	for (i;i >= 0;i--)
		cout << c[i];
	fclose(stdin);
	return 0;
}
