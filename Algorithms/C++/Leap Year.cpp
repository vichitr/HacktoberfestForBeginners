/* C++ Program - Check Leap Year or Not */

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{

	int yr;
	cout<<"--------Enter year :----------";
	cin>>yr;
	if((yr%4==0) && (yr%100!=0))
	{
		cout<<"This is a Leap Year";
	}
	else if((yr%100==0) && (yr%400==0))
	{
		cout<<"This is a Leap Year";
	}
	else if(yr%400==0)
	{
		cout<<"This is a Leap Year";
	}
	else
	{
		cout<<"This is not a Leap Year";
	}
	getch();
	return 0;
}
