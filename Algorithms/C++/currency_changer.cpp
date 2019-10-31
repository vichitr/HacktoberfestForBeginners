#include<iostream>
#include<climits>
using namespace std;

int currency(int *coins,int n,int amount){
	if(amount==0){
		return 0;
	}

	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if((amount-coins[i])>=0){
			int smallerans=currency(coins,n,amount-coins[i]);
			if(smallerans!=INT_MAX){
				ans=min(ans,smallerans+1);
			}
		}
	}
	return ans;
}

/*int topdown(int *coins,int n,int amount,int *dp){
	if(amount==0){
		dp[amount]=0;
		return dp[amount];
	}
	if(dp(dp[amount]))
}*/

int bottomup(int *coins,int n,int amount){
	int dp[1000];
	for(int i=0;i<1000;i++){
		dp[i]=INT_MAX;
	}
	dp[0]=0;

	for(int rupay=1;rupay<=amount;rupay++){
		for(int i=0;i<n;i++){
			if(rupay-coins[i]>=0){
				dp[rupay]=min(dp[rupay],dp[rupay-coins[i]]+1);
			}
		}
	}
	return dp[amount];
}

int main(){
	int coins[]={1,7,10};
	int n=sizeof(coins)/sizeof(int);

	int amount;
	cin>>amount;

	cout<<bottomup(coins,n,amount)<<endl;
	cout<<currency(coins,n,amount)<<endl;
	return 0;
}