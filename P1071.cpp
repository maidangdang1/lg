#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    string a, b;
    cin >> b >> a;
    int i;
    int len = a.length();
    char c[26];
    //bool d[26];
    memset(c, 0, sizeof(c));
    //memset(d, 0, sizeof(d));
    char temp1;
    char temp2;
    set <char> d;
    int cnt = 0;
    for (i = 0;i < len;i++)
    {
        temp1 = a[i];
        temp2 = b[i];
        if (c[temp2 - 65] && c[temp2 - 65] != temp1)
        {
            cout << "Failed";
            fclose(stdin);
            return 0;
        }
        else
        {
            c[temp2 - 65] = temp1;
            d.insert(temp1);
        }
    }
    if (d.size() != 26)
    {
        cout << "Failed";
        fclose(stdin);
        return 0;
    }
    string s;
    cin >> s;
    len = s.length();
    for (i = 0;i < len;i++)
        cout << c[s[i] - 65];
    fclose(stdin);
    return 0;
}