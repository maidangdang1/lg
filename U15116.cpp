#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	//int i;
	//vector<int> a;
	//vector<char> b;
	//string temp;
	//int len;
	//int j;
	int s = 0;
	int c = 0;
	//int temp1 = 1;
	char temp;
	/*
	for (i = 1;i <= n;i++)
	{
		cin >> temp;
		len = strlen(temp);
		for (j = 0;j < len;j++)
		{
			if (temp[j] == 's')
				s++;
			if (temp[j] == 'c')
				c++;
		}
	}
	*/
	while (cin >> temp)
	{
		if (temp == 's')
			s++;
		if (temp == 'c')
			c++;
	}
	if (s > c)
		cout << c;
	else
		cout << s;
	fclose(stdin);
	return 0;
}