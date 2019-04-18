#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int n;
int maxi = 0;
string ans[50];
int help[50];

struct node
{
    string ss;
    int data = 2;
};

bool check(int num)
{
    /*
    int i;
    int len;
    for (i = 1;i < n * 2;i++)
    {
        len = s[i].ss.length();
        if (s[i].ss == s[i + 1].ss.strncpy(0, len))
            return false;
    }
    return true;
    */
    int i;
    /*
    string temp1;
    string temp2;
    */
    int len1 = ans[num].ss.length();
    int len2 = ans[num + 1].ss.length();
    /*
    if (len1 < len2)
    {
        //strncpy(temp1, ans[num].ss)
        for (i = len1 - 1;i > 0;i--)
        {
            if (ans[num].ss[i] == ans[num + 1].ss[0])
            {
                help[num] = len1 - i;
                return true;
            }
        }
    }
    else
    {
        for (i = len2 - 1;i > 0;i--)
        {
            if (ans[num + 1].ss[i] == ans[num + 1].ss[0])
            {
                help[num] = len1 - i;
                return true;
            }
        }
    }
    */
   for (i = len1 - 1;i > 0;i--)
    {
        if (ans[num].ss[i] == ans[num + 1].ss[0] && len1 - i != )
        {
            help[num] = len1 - i;
            return true;
        }
    }
}

void dfs(int floor)
{
    int i;
    if (floor > n * 2)
    {
        for (i = 1;i < n * 2;i++)
        {
            if (check(i))
        }
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
    //int n;
    cin >> n;
    node s[n + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> s[i].ss;
    dfs(1);
}
