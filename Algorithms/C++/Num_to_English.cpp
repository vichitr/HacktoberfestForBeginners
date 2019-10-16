//convert the input number into the letters
#include<iostream>
#include<string>
using namespace std;


//Add a string
string addString(string str, string add)
{
	
	string s="";
/*	s+=add;
	s+=" ";
	s+=str;*/
	for(int i=0;add[i]!='\0';i++)
	{
		s+=add[i];
	}
		s+=" ";
	for(int i=0;str[i]!='\0';i++)
	{
		s+=str[i];
	}
	return s;
	
}

//Convert the hundredth terms into the corresponding letters
string hunDigToLetter(string str, int num)
{
	int r;
	r=num%10;
	if(r!=0)
	{
		str = addString( str,  "Hundred");
		switch (r)
			{	
				case 1:
					str= addString(str , "One");
					break;
				case 2:
					str= addString(str , "Two");
					break;
				case 3:
					str= addString(str , "Three");
					break;
				case 4:
					str= addString(str , "Four");
					break;
				case 5:
					str= addString(str , "Five");
					break;
				case 6:
					str= addString(str , "Six");
					break;
				case 7:
					str= addString(str , "Seven");
					break;
				case 8:
					str= addString(str , "Eight");
					break;
				case 9:
					str= addString(str , "Nine");
					break;
				default:
					break;
			}
		}
		return str;
}

//Convert the ones term into corresponding letters
string onesDigToLetter(string str, int num)
{
	int r;
		r=num%10;
		if((num/10)%10==1)
		{
				switch (r)
			{
				case 0:
					str= addString(str , "Ten");
					break;
					
				case 1:
					str= addString(str , "Eleven");
					break;
				case 2:
					str= addString(str , "Twelve");
					break;
				case 3:
					str= addString(str , "Thirteen");
					break;
				case 4:
					str= addString(str , "Fourteen");
					break;
				case 5:
					str= addString(str , "Fifteen");
					break;
				case 6:
					str= addString(str , "Sixteen");
					break;
				case 7:
					str= addString(str , "Seventeen");
					break;
				case 8:
					str= addString(str , "Eighteen");
					break;
				case 9:
					str= addString(str , "Nineteen");
					break;
				default:
					break;
			}
		}
		else
		{
		
			switch (r)
			{	
				case 1:
					str= addString(str , "One");
					break;
				case 2:
					str= addString(str , "Two");
					break;
				case 3:
					str= addString(str , "Three");
					break;
				case 4:
					str= addString(str , "Four");
					break;
				case 5:
					str= addString(str , "Five");
					break;
				case 6:
					str= addString(str , "Six");
					break;
				case 7:
					str= addString(str , "Seven");
					break;
				case 8:
					str= addString(str , "Eight");
					break;
				case 9:
					str= addString(str , "Nine");
					break;
				default:
					break;
			}
		}
			return str;
				
}

//Convert the tens term into corresponding letters
string tensDigToLetter(string str, int num)
{
	int r;
			r=num%10;
				switch (r)
				{
				case 2:
					str= addString(str , "Twenty");
					break;
				case 3:
					str= addString(str , "Thirty");
					break;
				case 4:
					str= addString(str , "Forty");
					break;
				case 5:
					str= addString(str , "Fifty");
					break;
				case 6:
					str= addString(str , "Sixty");
					break;
				case 7:
					str= addString(str , "Seventy");
					break;
				case 8:
					str= addString(str , "Eighty");
					break;
				case 9:
					str= addString(str , "Ninety");
					break;
				default:
					break;
				}
			return str;
}

int main ()
{
	long long num ;
	string str="";
	cout<<"Enter the number to convert it into English but the number must be less than 1 billion:\n";
	cin>>num;
	if(num<1000000000)  //convert numbers less than 1 billion
	{
	
	//	cout<<num;
	for(int i=0;num!=0;i++)
	{			

		if(i==0)
		{
			str = onesDigToLetter( str, num);
		}
	
			if(i==1)
			{
				str = tensDigToLetter( str, num);
			}
			
				if(i==2)
				{	
					if(num%10!=0)	
					{
							
						str = hunDigToLetter( str, num);
					}
				}
			
					if(i==3)
					{
						if(num%1000!=0)
						{						
							str = addString( str,  "Thousand");
							for(i; num!=0 && i<=5;i++)
							{		

								if(i==3)
								{
									str = onesDigToLetter( str, num);
								}
								if(i==4)
								{
									str = tensDigToLetter( str, num);
								}
								if(i==5)
								{
									str = hunDigToLetter( str, num);						
								}
								num=num/10;
							}
						}
					}
					
						if(i==6)
						{
							if(num%1000!=0)
							{
							
							str = addString( str,  "Million");
							for(i;num!=0 && i<=8;i++)
							{			

								if(i==6)
								{
									str = onesDigToLetter( str, num);
								}
								if(i==7)
								{
									str = tensDigToLetter( str, num);
								}
								if(i==8)
								{
									str = hunDigToLetter( str, num);								
								}
								num=num/10;
							}
							
							}
						}
						
							if(i==9)
							{
								if(num%1000!=0)
								{
								
								str = addString( str,  "Billion");
								for(i;num!=0 && i<=11;i++)
								{			

									if(i==9)
									{
										str = onesDigToLetter( str, num);
									}
									if(i==10)
									{
										str = tensDigToLetter( str, num);
									}
									if(i==11)
									{
										str = hunDigToLetter( str, num);								
									}
									num=num/10;
								}
								
								}
							}
								
									if(i==12)
									{
										
										str = addString( str,  "Trillion");
										for(i;num!=0 && i<=14;i++)
										{		

											if(i==12)
											{
												str = onesDigToLetter( str, num);
											}
											if(i==13)
											{
												str = tensDigToLetter( str, num);
											}
											if(i==14)
											{
												str = hunDigToLetter( str, num);											
											}
											num=num/10;
										}
										
									}
								
							
						
					
				
			
		
		num=num/10;
	}
	cout<<endl<<str;
	}
	else
		cout<<"Your number is greater than 1 billion.\n";
	return 0;
}
