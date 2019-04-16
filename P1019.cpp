#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int n;
int maxi = 0;
string ans[n * 2 + 10];

struct node
{
    string ss;
    int data = 2;
};

bool check()
{
    int i;
    int len;
    for (i = 1;i < n * 2;i++)
    {
        len = s[i].ss.length();
        if (s[i].ss == s[i + 1].ss.strncpy(0, len))
            return false;
    }
    return true;
}

void dfs(int floor)
{
    int i;
    if (floor > n * 2)
    {
        if (check())
        {

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