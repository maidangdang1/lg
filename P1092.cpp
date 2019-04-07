/*
21
BADCEFGHIJKLMNOPQRSTU
BADCEFGHIJKLMNOPQRSTU
BDEGIKMOQTBDEGIKMOQST
*/
/*
1 0 3 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
/*
16
MOBNHFLIKGEJDACP
AKLDNCECMMFBFHJC
PENEMJLFCPJMKJNE
*/
/*
10 14 1 7 0 5 11 12 3 6 13 9 4 8 2 15
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
bool book[27];
char add1[27];
char add2[27];
char sum[27];
int pailie[27];
bool yanzheng()
{
	int temp1;
	int temp2;
	int temp3;
	int jinwei;
	int com;
	bool corr;
	corr = true;
	int i;
	jinwei = 0;
	temp1 = pailie[add1[1] - 'A'];
	temp2 = pailie[add2[1] - 'A'];
	if (temp1 + temp2 + 1 >= n)
		return false;
	for (i = n;i >= 1;i--)
	{
		temp1 = pailie[add1[i] - 'A'];
		temp2 = pailie[add2[i] - 'A'];
		temp3 = pailie[sum[i] - 'A'];
		com = temp1 + temp2 + jinwei;
		if (com % n == temp3)
			jinwei = com / n;
		else
		{
			corr = false;
			break;
		}
	}
	if (corr)
		return true;
	else
		return false;
}
bool jianzhi()
{
	int i;
	for (i = 1;i <= n;i++)
	{
		int temp1 = pailie[add1[i] - 'A'];
		int temp2 = pailie[add2[i] - 'A'];
		int temp3 = pailie[sum[i] - 'A'];
		if (temp1 >= 0 && temp2 >= 0 && temp3 >= 0 && (temp1 + temp2) % n != temp3 && (temp1 + temp2 + 1) % n != temp3)
			return false;
	}
	return true;
}
void permu(int a)
{
	int i;
	if (a == n)
	{
		if (yanzheng())
		{
			for (i = 0;i < n;i++)
				cout << pailie[i] << " ";
			exit(0);
		}
	}
	else
	{
		for (i = n - 1;i >= 0;i--)
		{
			if (book[i] == false)
			{
				book[i] = true;
				pailie[a] = i;
				if (jianzhi())
					permu(a + 1);
				book[i] = false;
				pailie[a] = -1;
			}
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n;
	memset(book, false, sizeof(book));
	/*
	char add1[n + 1];
	char add2[n + 1];
	char sum[n + 1];
	int pailie[n + 1];
	*/
	int i;
	for (i = 1;i <= n;i++)
		cin >> add1[i];
	for (i = 1;i <= n;i++)
		cin >> add2[i];
	for (i = 1;i <= n;i++)
		cin >> sum[i];
	for (i = 0;i < n;i++)
		pailie[i] = -1;
	permu(0);
	f:
	/*
	while (next_permutation(pailie, pailie + n))
	{
		/*
		for (i = 0;i < n;i++)
			cout << pailie[i] << " ";
		cout << endl;
		
		corr = true;
		jinwei = 0;
		for (i = n;i >= 1;i--)
		{
			temp1 = pailie[add1[i] - 'A'];
			temp2 = pailie[add2[i] - 'A'];
			temp3 = pailie[sum[i] - 'A'];
			com = temp1 + temp2;
			if ((com + jinwei) % n == temp3)
				jinwei = (com + jinwei) / n;
			else
			{
				corr = false;
				break;
			}
		}
		if (corr)
		{
			for (i = 0;i < n;i++)
				cout << pailie[i] << " ";
		}
	}
	*/
	fclose(stdin);
	return 0;
}
