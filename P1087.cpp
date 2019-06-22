#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

char ans[100010];
//string s;

inline string mycpy(string s, int first, int last)
{
    int i;
    string ans;
    for (i = first;i < last;i++)
        ans += s[i];
    return ans;
}

void make(string now, int floor)
{
    int len = now.length();
    int i;
    bool isone = false;
    bool iszero = false;
    if (len == 1)
    {
        if (now == "0")
            ans[floor] = 'B';
        else
            ans[floor] = 'I';
        return;
    }
    else
    {
        for (i = 0;i < len;i++)
        {
            if (now[i] == '0')
                iszero = true;
            else
                isone = true;
        }
        if (isone)
        {
            if (iszero)
                ans[floor] = 'F';
            else
                ans[floor] = 'I';
        }
        else
            ans[floor] = 'B';
        make(mycpy(now, 0, len >> 1), floor << 1);
        make(mycpy(now, len >> 1, len), (floor << 1) + 1);
    }
}

void dfs(int floor)
{
    if (ans[floor] == 0)
        return;
    dfs(floor << 1);
    dfs((floor << 1)+ 1);
    cout << ans[floor];
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    //int len = s.length();
    make(s, 1);
    dfs(1);
    fclose(stdin);
    return 0;
}
