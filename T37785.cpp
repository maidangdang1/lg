#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool comp(string x, string y)
{
	return x < y;
}
char temp2[1010];
bool teachercheck[3];
int teachernum;
bool studentplay[5];
bool nonplay = true;
bool pdteacher = false;
bool pdstudent = false;
int studentnum;
void pd()
{
	if (pdteacher == true)
	{
		if (temp2 == " came!")
			teachercheck[teachernum] = true;
		else if (temp2 == " left!")
			teachercheck[teachernum] = false;
	}
	else if (pdstudent == true)
	{
		if (temp2 == " started playing games!")
		{
			studentplay[studentnum] = true;
			nonplay = false;
		}
		else if (temp2 == " stopped playing games!")
			studentplay[studentnum] = false;
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	int n;
	cin >> n;
	string teacher[3];
	string student[5];
	
	
	int i;
	for (i = 0;i < 3;i++)
		cin >> teacher[i];
	for (i = 0;i < 5;i++)
		cin >> student[i];
	string temp1;
	//string temp2;
	char came[] = " came!";
	char left[] = " left!";
	char play[] = " started playing games!";
	char stopplay[] = " stopped playing games!";
	
	bool catched[5];
	bool checking = false;
	
	memset(teachercheck, false, sizeof(teachercheck));
	memset(studentplay, false, sizeof(studentplay));
	memset(catched, false, sizeof(catched));
	string fin[5];
	int j;
	for (i = 1;i <= n;i++)
	{
		cin >> temp1;
		gets(temp2);
		for (j = 0;j < 3;j++)
		{
			if (temp1 == teacher[j]) 
			{
				pdteacher = true;
				teachernum = i;
				break;
			}
		}
		for (j = 0;j < 5;j++)
		{
			if (temp1 == student[j])
			{
				pdstudent = true;
				studentnum = i;
				break;
			}
		}
		cout << temp1 << teacher[teachernum] << endl;
		cout << temp1 << student[studentnum] << endl;
		/*
		goto y;
		y:
		*/
		//pd();
		if (pdteacher)
		{
			if (strcmp(temp2, came) == 0)
				teachercheck[teachernum] = true;
			else if (strcmp(temp2, left) == 0)
				teachercheck[teachernum] = false;
		}
		else if (pdstudent)
		{
			if (strcmp(temp2, play) == 0)
			{
				studentplay[studentnum] = true;
				nonplay = false;
			}
			else if (strcmp(temp2, stopplay) == 0)
				studentplay[studentnum] = false;
		}
		for (j = 0;j < 3;j++)
		{
			if (teachercheck[j] == true)
			{
				checking = true;
				break;
			}
		}
		if (checking)
		{
			for (j = 0;j < 5;j++)
			{
				if (studentplay[j])
					catched[j] = true;
			}
		}
		for (j = 0;j < 3;j++)
			cout << teachercheck[j];
		cout << endl;
		for (j = 0;j < 5;j++)
			cout << studentplay[j];
		cout << endl;
		cout << checking << endl;
		pdteacher = false;
		pdstudent = false;
		checking = false;
		for (j = 0;j < 5;j++)
			cout << catched[j] << " ";
		cout << endl;
		cout << endl;
	}
	int cnt = 0;
	for (i = 0;i < 5;i++)
	{
		if (catched[i])
		{
			fin[cnt] = student[i];
			cnt++;
		}
	}
	if (cnt == 0 || nonplay)
	{
		cout << "How Good Oiers Are!";
		return 0;
	}
	sort(fin, fin + cnt, comp);
	for (i = 0;i < cnt;i++)
		cout << fin[i] << " ";
	cout << endl;
	if (cnt == 5)
		cout << "How Bad Oiers Are!";
	fclose(stdin);
	return 0;
}
