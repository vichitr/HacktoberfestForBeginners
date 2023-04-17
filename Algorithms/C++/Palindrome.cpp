/* C++ Program - Check Palindrome or Not */

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{

	int num,orig, rev=0;
	cout<<"------Enter The number :--------- ";
	cin>>num;
	orig=num;
	while(num!=0)
	{
		rev= (rev * 10) + num % 10;
		num /= 10;
	}
	if(rev == orig)  // check if original number is equal to its reverse
	{
		cout<<"A Palindrome";
	}
	else
	{
		cout<<"Not a Palindrome";
	}
	getch();
	return 0;
}
