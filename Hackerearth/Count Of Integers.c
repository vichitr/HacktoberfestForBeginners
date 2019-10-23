    #include<stdio.h>
    #include<stdlib.h>
    #define SIZE 1000001
    typedef long int ll;
    ll Find(ll Prime[],ll N){
    	ll temp=N,curr=Prime[N];
    	while(N>1){
    		N/=Prime[N];
    		if(Prime[N]!=curr){
    			temp=(temp/curr)*(curr-1);
    			curr=Prime[N];
    		}
    	}
    	return(temp);
    }
    int main(){
    	ll i,j,N,Q;
    	ll *Prime=(ll *)malloc(SIZE*sizeof(ll));
    	ll *count=(ll *)malloc(SIZE*sizeof(ll));
    	ll *Sum=(ll *)malloc(SIZE*sizeof(ll));
    	for(i=0;i<SIZE;i++){
    		Prime[i]=i;
    		count[i]=1;
    	}
    	for(i=2;i*i<SIZE;i++){
    		for(j=i*i;j<SIZE;j+=i){
    			if(Prime[j]==j)
    				Prime[j]=i;
    			(j==i*i)?(count[j]+=1):(count[j]+=2);
    		}
    	}
    	for(i=0;i<SIZE;i++)
    		(Prime[i]==i)?(Sum[i]=0):(Sum[i]=i-Find(Prime,i)-count[i]);
    	scanf("%ld",&Q);
    	while(Q--){
    		scanf("%ld",&N);
    		printf("%ld\n",Sum[N]);
    	}
    	return(0);
    }
