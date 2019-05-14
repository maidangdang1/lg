#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int n;
int maxi = 0;
string ans[50];
int help[50];
int nowans;

struct node
{
    string ss;
    int data = 2;
}s[30];

bool check(int num)
{
    int i;
    int len1 = ans[num].length();
    int len2 = ans[num + 1].length();
    if (len1 <= len2)
    {
        for (i = 0;i < len1;i++)
        {
            if (ans[num][i] != ans[num + 1][i])
                break;
        }
        if (i == len1)
            return false;
    }
    else
    {
        for (i = 0;i < len2;i++)
        {
            if (ans[num][i] != ans[num + 1][i])
                break;
        }
        if (i == len2)
            return false;
    }
    int j;
    int temp;
    for (i = 1;i < len1;i++)
    {
        temp = 0;
        for (j = len1 - i;j < len1;j++)
        {
            if (ans[num][j] != ans[num + 1][temp])
                break;
            temp++;
        }
        if (j == len1)
        {
            help[num] = i;
            return true;
        }
    }
}

void dfs(int floor)
{
    int i;
    int j;
    if (floor > n * 2)
    {
    	memset(help, 0, sizeof(help));
        for (i = 1;i < n * 2;i++)
        {
            //cout << ans[i] << " ";
            if (check(i) == false)
            {
                nowans = 0;
                for (j = 1;j <= i;j++)
                    nowans += ans[j].length();
                for (j = 1;j < i;j++)
                    nowans -= help[j] * 2;
                if (nowans > maxi)
                {
                	maxi = nowans;
                	for (j = 1;j <= i;j++)
                		cout << ans[j] << " ";
                	cout << endl;
				}
            }
        }
        //cout << endl;
    }
    else
    {
        for (i = 1;i <= n;i++)
        {
            if (s[i].data)
            {
                ans[floor] = s[i].ss;
                s[i].data--;
                dfs(floor + 1);
                s[i].data++;
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
    for (i = 1;i <= n;i++)
        cin >> s[i].ss;
    dfs(1);
    cout << maxi;
    fclose(stdin);
    return 0;
}
