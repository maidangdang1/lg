#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int n;
int isprime[1010];
int primenum = 0;
int up = 1;
int ans = 0;
int help[510];
bool found = false;

void prime()
{
    bool help[1010];
    memset(help, true, sizeof(help));
    //help[2] = true;
    int i;
    int j;
    for (i = 2;i <= 1000;i++)
    {
        if (help[i])
        {
            isprime[primenum] = i;
            primenum++;
            for (j = i * 2;j <= 1000;j += i)
                help[j] = false;
        }
    }
}

bool dfs(int floor)
{
    int i;
    int sum = 0;
    if (up < floor)
    {
        for (i = 1;i <= up;i++)
            sum += help[i];
        if (sum == n)
        {
            found = true;
            ans++;
        }
    }
    else
    {
        for (i = 0;i < primenum;i++)
        {
            if (isprime[i] >= help[floor - 1])
                break;
        }
        for (i;i < primenum;i++)
        {
        	if (isprime[i] > n)
        		break;
            help[floor] = isprime[i];
            dfs(floor + 1);
        }
    }
}

int main()
{
    freopen("test.txt", "r", stdin);
    //int n;
    cin >> n;
    prime();
    for (up;up <= n / 2;up++)
        dfs(1);
    cout << ans;
    fclose(stdin);
    return 0;
}
