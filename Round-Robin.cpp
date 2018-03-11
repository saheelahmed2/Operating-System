#include<iostrem.h>
#include<stdio.h>

using namespace std;

int main(){

	int i,j,n,max,t_slice,burst_time[i],wait_time[10],turn_around_time[10],c_t[10];
	float avg_tat_time,avg_wait_time,temp=0;
	clrscr();
	cout<<"\nEnter the no. of process:--";
	cin<<n;
	cout<<"\nEnter the time slice:--";
	cin>>t_slice;
	cout<<"\nEnter the arrival and burst time:--";
	for ( i = 0; i < n; i++)
	{	cin>>burst_time[i];
		c_t[i]=burst_time[i];
	}
	max=burst_time[0];
	for ( i = 1; i < n; i++)
	{
		if(max<burst_time[i])
			max=burst_time[i];
	}
	for ( j = 0; j < (max/t_slice)+1; j++)
	{
		for ( i = 0; i < n; i++)
		{
			if(burst_time[i]!=0){
				
					if(burst_time[i]<=t_slice){

						turn_around_time[i]=temp+burst_time[i];
						temp=temp+burst_time[i];
						burst_time[i]=0;
					}
					else{

						burst_time[i]-=t_slice;
						temp+=t;
					}
			}

		}
	}
	for ( i = 0; i < n; i++)
	{
		wait_time[i]=turn_around_time[i]-c_t[i];
		avg_tat_time+=turn_around_time[i];
		avg_wait_time+=wait_time[i]
	}
	cout<<"\tPROCESS\tBURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for(i=0;i<n;i++){
        cout<<"\n\tP"<<i<<"\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turn_around_time[i];
    }
    cout<<"\nAverage Waiting Time --"<<avg_wait_time/n;
    cout<<"\nAverage Turnaround Time --"<<avg_tat_time/n;
    return 0;

}