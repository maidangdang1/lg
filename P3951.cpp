#include <iostream>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
    long long a, b;
    cin >> a >> b;
    unsigned long long temp = a * b;
    cout << temp - a - b;
    fclose(stdin);
    return 0;
}
