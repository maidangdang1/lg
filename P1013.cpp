#include <iostream>
#include <cstring>

using namespace std;

struct node
{
	char charater;
	int data;
};

int trans[19][19];
string sta[19][19];
int trans10[19][19];
int n;
node ans[19];
bool book[19];

int singletrans(string s)
{
	int i;
	int temp = 0;
	int cnt = 0;
	int len = s.length();
	while (len--)
	{
		for (i = 1;i < n;i++)
		{
			if (ans[i].charater == s[temp])
			   cnt = cnt * 10 + ans[i].data;
		}
		temp++;
	}
	return cnt;
}

bool translate()
{
	int i;
	int j;
	for (i = 1;i < n;i++)
	{
		trans[i][0] = ans[i].data;
		trans[0][i]=  ans[i].data;
	}
	for (i = 1;i < n;i++)
	{
		for (j = 1;j < n;j++)
		{
			trans[i][j] = singletrans(sta[i][j]);
			if (trans[i][j] > 20)
			   return false;
		}
	}
	return true;
}

void translateto10()
{
	int i;
	int j;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (trans[i][j] < 10)
			   trans10[i][j] = trans[i][j];
			else
			{
				trans10[i][j] = n - 1 + trans[i][j] % 10;
			}
		}
	}
}

bool judge()
{
	int i;
	int j;
	for (i = 1;i < n;i++)
	{
		for (j = 1;j < n;j++)
		{
			if (trans10[i][j] != trans10[i][0] + trans10[0][j])
				return false;
		}
	}
	return true;
}

void dfs(int floor)
{
	int i;
	if (floor == n)
	{
		if (translate() == false)
			return;
		else
		{
			translateto10();
			if (judge())
			{
				for (i = 1;i < n;i++)
					cout << ans[i].charater << "=" << ans[i].data << " ";
				cout << endl << n - 1;
				exit(0);
			}
		}
	}
	else
	{
		for (i = 0;i < n - 1;i++)
		{
			if (book[i] == false)
			{
				book[i] = true;
				ans[floor].data = i;
				dfs(floor + 1);
				book[i] = false;
			}
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	//int n;
	cin >> n;
	int i;
	int j;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
			cin >> sta[i][j];
	}
	for (i = 1;i < n;i++)
		ans[i].charater = sta[0][i].at(0);
	dfs(1);
	cout << "ERROR!";
	fclose(stdin);
	return 0; 
}
