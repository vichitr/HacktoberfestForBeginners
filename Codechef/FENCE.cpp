#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int k ;
		cin>>k;
		set<pair<int,int>> s1,s2;
		for(int i = 0;i<k;i++)
		{
			int r,c;
			cin>>r>>c;
			s1.insert({r,c});
			s2.insert({r,c});
		}
		int ans = 0;
		for(auto x : s1)
		{
			int r = x.first;
			int c = x.second;
			int left = 0,right = 0,up = 0,down = 0;
		    if(c==0)
		    {
		    	if(r==0) {
		    		left = 1;
		    		up = 1;
		    		if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
						//s2.insert({r+1,c});
					}
				}
				else if(r==n)
				{
					left = 1;
					down = 1;
					if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
						//s2.insert({r-1,c});
					}
					if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
					down = 1;
					
				}	
				
				else{
					left = 1;
					if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
						//s2.insert({r-1,c});
					}
					if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
						//s2.insert({r+1,c});
					}
					
					
				}
			}
			
			else if(r==0)
			{
			   	if(c==0) {
				   
		    		left = 1;
		    		up = 1;
			   		if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
					
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
						//s2.insert({r+1,c});
					}
				}
			
				
				else if(c==m)
				{
				up = 1;
				right = 1;
					if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
						//s2.insert({r,c-1});
					}
					
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
						//s2.insert({r+1,c});
					}
						
				}
				else{
					up = 1;
					if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
						//s2.insert({r,c-1});
					}
					if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
						//s2.insert({r+1,c});
					}
					
					
				}
			}
			
			else if(r==n)
			{
				 if(c==0) {
		    		left = 1;
		    		down = 1;
				   	if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
						//s2.insert({r-1,c});
					}
					if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
				
				}
				else if(c==m)
				{
						right = 1;
						down = 1;
					if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
						s2.insert({r,c-1});
					}
					if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
						//s2.insert({r-1,c});
					}
					
				}
				else{
					down = 1;
					if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
						//s2.insert({r,c-1});
					}
					if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
						//s2.insert({r,c+1});
					}
					if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
						//s2.insert({r-1,c});
					}
					
					
				}
			}
			else if(c==m)
			{
				if(r==0)
				{
					up =1;
					right = 1;
						if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
						//s2.insert({r,c-1});
					}
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						up = 1;
						//s2.insert({r+1,c});
					}
				
				}
				else if(r==n)
				{
					right = 1;
					down = 1;
						if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
						//s2.insert({r-1,c});
					}
					if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
						//s2.insert({r,c-1});
					}
				
				}
				else{
				     right = 1;
						if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
					//	s2.insert({r,c-1});
					}
					if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
					//	s2.insert({r-1,c});
					}
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
					//	s2.insert({r+1,c});
					}
				
				}
			}
			else{
						if(s2.find({r,c-1})!=s2.end())
					{
						left = 0;
					}
					else {
						left = 1;
					//	s2.insert({r,c-1});
					}
					if(s2.find({r-1,c})!=s2.end())
					{
						up = 0;
					}
					else {
						up = 1;
					//	s2.insert({r-1,c});
					}
					if(s2.find({r+1,c})!=s2.end())
					{
						down = 0;
					}
					else {
						down = 1;
					//	s2.insert({r+1,c});
					}
						if(s2.find({r,c+1})!=s2.end())
					{
						right = 0;
					}
					else {
						right = 1;
					//	s2.insert({r,c+1});
					}
				
				
			}
		//	cout<<r<<" "<<c<<endl;
		//	cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;
			ans+=left+right+up+down;
		}
		cout<<ans<<endl;
	}
}

