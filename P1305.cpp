#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char ans[1034];

void dfs(int floor)
{
    if (ans[floor] == '*' || ans[floor] == 0)
        return;
    else
        cout << ans[floor];
    dfs(floor * 2);
    dfs(floor * 2 + 1);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    //char ans[n + 10];
    //memset(ans, 0, sizeof(ans));
    char temp1, temp2, temp3;
    int i;
    int j;
    int flag = 0;
    for (i = 1;i <= n;i++)
    {
        flag = 0;
        cin >> temp1 >> temp2 >> temp3;
        for (j = 1;j <= 1000;j++)
        {
            if (ans[j] == temp1)
            {
                flag = j;
                break;
            }
        }
        if (flag)
        {
            ans[flag] = temp1;
            ans[flag * 2] = temp2;
            ans[flag * 2 + 1] = temp3;
        }
        else
        {
            ans[i] = temp1;
            ans[i * 2] = temp2;
            ans[i * 2 + 1] = temp3;
        }
    }
    dfs(1);
    //fclose(stdin);
    return 0;
}
