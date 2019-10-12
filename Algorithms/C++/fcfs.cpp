#include<bits/stdc++.h>
using namespace std;

struct process{
	int arr_t, bur_t, comp_t, tat, wait_t;
	string pro_id;
};

bool compare_arr_t(process a,process b)
{
	return a.arr_t<b.arr_t;
}

int main(){
	int n, i, t, sum=0;
	cout<<"Enter the number of process:\t";
	cin>>n;
	process p[10];
	cout<<"\nEnter the arrival time and burst time respectively of each process::\n";
	for(i=0;i<n;i++){
		char c = static_cast<char>(i);
		p[i].pro_id = 'A' + c;
		cout<<"P"<<i+1<<"\tArrival Time: ";
		cin>>p[i].arr_t;
		cout<<"\tBurst Time: ";
		cin>>p[i].bur_t;
	}
	//cout<<"\n";
	sort(p,p+n,compare_arr_t);
	for(i=0;i<n;i++){
		cout<<p[i].pro_id<<" "<<p[i].arr_t<<" "<<p[i].bur_t<<"\n";
	}
	float av_tat=0, av_wait=0;
	sum = p[0].arr_t;
	for(i=0;i<n;i++){
		sum += p[i].bur_t;
		p[i].comp_t = sum;
		p[i].tat = p[i].comp_t - p[i].arr_t;
		p[i].wait_t = p[i].tat - p[i].bur_t;
		av_tat += p[i].tat;
		av_wait += p[i].wait_t;
		if(i!=n-1){
		if(p[i].comp_t<p[i+1].arr_t){
			sum=p[i+1].arr_t;
		}}
	}
	av_tat /= n;
	av_wait /= n;
	cout<<"ProcessID\tArrivalTime\tBurstTime\tCompTime\tTurnAroundTime\tWaitingtime\n";
	for(i=0;i<n;i++){
		cout<<p[i].pro_id<<"\t\t"<<p[i].arr_t<<"\t\t"<<p[i].bur_t<<"\t\t"<<p[i].comp_t<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wait_t;
		cout<<endl;
	}
	cout<<"\nAverage Waiting Time = "<<av_wait<<" , Average Turn Around Time = "<<av_tat;
	cout<<"\n\n";
	cout<<"----------------------------------GANTT CHART------------------------------------------------------";
	cout<<"\n||\t";
	for(i=0;i<n;i++){
		cout<<p[i].comp_t-p[i].bur_t<<" -P"<<i+1<<"- "<<p[i].comp_t;
		cout<<"\t||\t"; 
	}
	cout<<"\n---------------------------------------------------------------------------------------------------";
	cout<<"\n\n";
	return 0;
}