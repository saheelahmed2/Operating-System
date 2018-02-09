#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int burst_time[10],temp,j,arrival_time[10],wait_time[10],turn_around_time[10],ta=0,sum=0;
float total_tat_time=0,total_wait_time=0;
cout<<" -------Shortest Job First Scheduling ( NP )-------\n";
cout<<"\nEnter the No. of processes :";
cin>>n;
 
for(i=0;i<n;i++)
{
cout<<"\nEnter the burst time of"<<i+1<<"process :";
cin>>burst_time[i];
cout<<"\nEnter the arrival time of"<<i+1<<"process :";
cin>>arrival_time[i];
}
 
/*Sorting According to Arrival Time*/
 
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(arrival_time[i]<arrival_time[j])
		{
			temp=p[j];
			p[j]=p[i];
			p[i]=temp;
	
			temp=arrival_time[j];
			arrival_time[j]=arrival_time[i];
			arrival_time[i]=temp;
	
			temp=burst_time[j];	
			burst_time[j]=burst_time[i];
			burst_time[i]=temp;
		}
	}
}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
for(j=0;j<n;j++)
	{
		btime=btime+burst_time[j];
		min=burst_time[k];
		for(i=k;i<n;i++)
		{
			if (btime>=arrival_time[i] && burst_time[i]<min)
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;

					temp=arrival_time[k];
					arrival_time[k]=arrival_time[i];
					arrival_time[i]=temp;
					
					temp=burst_time[k];
					burst_time[k]=burst_time[i];
					burst_time[i]=temp;
				}
		}
		k++;
	}
	wait_time[0]=0;
for(i=1;i<n;i++)
	{
		sum=sum+burst_time[i-1];
		wait_time[i]=sum-arrival_time[i];
		total_wait_time=total_wait_time+wait_time[i];
	}
 

for(i=0;i<n;i++)
	{
		ta=ta+burst_time[i];
		turn_around_time[i]=ta-arrival_time[i];
		total_tat_time=total_tat_time+turn_around_time[i];
	}
 

cout<<"\tPROCESS\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
for(i=0;i<n;i++){                                                   //displaying the burst,wait & turn around time
        cout<<"\n\tP"<<p[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turn_around_time[i];
    } 
cout<<"\nAverage Waiting Time --"<<total_wait_time/n;                 //displaying the Average Waiting time
cout<<"\nAverage Turnaround Time --"<<total_tat_time/n;               //displaying the Average TurnAround time
return 0;
}