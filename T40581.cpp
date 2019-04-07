#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	string name1, name2;
	cin >> name1 >> name2;
	string type;
	double power;
	double angel;
	double calibre;
	double thickness;
	cin >> type >> power >> angel >> calibre >> thickness;
	double change = 0;
	if (type == "AP")
		change = 5;
	else if (type == "APCR" || type == "APFSDS")
		change = 2;
	if (calibre > thickness * 3)
		change *= 3;
	else if (calibre > thickness * 2)
		change *= 2;
	double min = power * 0.75;
	double max = power * 1.25;
	double realangle = angel - change;
	double rad = realangle * 3.14 / 180;
	double realthick = thickness / cos(rad);
	//cout << cos(90) << endl;
	//cout << realangle << " " << realthick << " " << min << endl;
	if ((type == "AP" || type == "APCR" || type == "APFSDS") && realangle >= 70)
	{
		cout << "We didn't penetrate their armor!";
		return 0;
	}
	else if (type == "HEAT" && realangle >= 85)
	{
		cout << "We didn't penetrate their armor!";
		return 0;
	}
	if (realthick > max)
		cout << "We didn't penetrate their armor!";
	else if (realthick > min)
		cout << "Server is important~";
	else
		cout << "Penetration!";
	fclose(stdin);
	return 0;
}