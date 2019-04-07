#include <iostream>
using namespace std;
int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n + 1];
    int i;
    for (i = 1;i <= n;i++)
        cin >> a[i];
    int cou = 1;
    for (i = 2;i <= n;i++)
    {
        if (a[i] != a[i - 1])
            cou++;
    }
    if (a[n] == a[1])
    {
    	if (cou == 1)
    		;
    	else
    		cou--;
	}
    cout << cou;
    fclose(stdin);
    return 0;
}
