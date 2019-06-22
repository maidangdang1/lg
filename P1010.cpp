#include <iostream>

using namespace std;

int help[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};

void dfs(int temp)
{
    if (temp == 2)
    {
        cout << 2;
        return;
    }
    if (temp == 0)
    {
        cout << "0";
        return;
    }
    int i;
    bool flag = false;
    while (temp)
    {
        if (flag)
            cout << "+";
        for (i = 14;i >= 0;i--)
        {
            if (temp - help[i] >= 0)
            {
            	if (help[i] == 2)
                    cout << 2;
                else if (help[i] == 1)
                    cout << "2(0)";
                else
                {
                    cout << "2(";
                    dfs(i);
                    cout << ")";
                }
                break;
            }
        }
        temp -= help[i];
        flag = true;
    }
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    dfs(n);
    fclose(stdin);
    return 0;
}
