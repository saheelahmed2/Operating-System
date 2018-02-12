#include<iostream>
using namespace std;

int min(int burstTime[],int arrivalTime[], int priority[], int current)
{
	int min = 0;
	for(int i=1;i<4;i++)
	{
		if(burstTime[min] == 0)
			min = i;
		if(priority[i] < priority[min] && current >= arrivalTime[i] && burstTime[i]!=0)
			min = i;
	}
	return min;
}

void incWaitTime(int index,int current, int waitTime[], int arrivalTime[], int burstTime[])
{
	for(int i=0;i<4;i++)
	{
		if(i!=index && current>=arrivalTime[i] && burstTime[i]>0)
			waitTime[i]++;
	}
}

void display(int burstTime[], int arrivalTime[], int waitTime[], int turnaroundTime[], int priority[])
{
	cout<<"PID\tPriority\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n";
	for(int i=0;i<4;i++)
		cout<<"P"<<i<<"\t"<<priority[i]<<"\t\t"<<burstTime[i]<<"\t\t"<<arrivalTime[i]<<"\t\t"<<waitTime[i]<<"\t\t"<<turnaroundTime[i]<<'\n';
}

void prioritySched(int burstTime[], int waitTime[], int arrivalTime[], int turnaroundTime[], int priority[], int totalBurst)
{
	int index, tempBurstTime[4];
	for(int i=0;i<4;i++)
		tempBurstTime[i] = burstTime[i];
	index = min(tempBurstTime, arrivalTime, priority, 0);
	for (int i=0;i<=totalBurst;i++)
	{
		if(tempBurstTime[index] == 0)
			index = min(tempBurstTime, arrivalTime, priority, i);
		
		tempBurstTime[index]--;
		incWaitTime(index, i, waitTime, arrivalTime, tempBurstTime);
	}
	for(int i=0;i<4;i++)
		turnaroundTime[i] = waitTime[i] + burstTime[i];
	display(burstTime, arrivalTime, waitTime, turnaroundTime, priority);
}

int main()
{
	int burstTime[4], arrivalTime[4], waitTime[4], turnaroundTime[4], priority[4], totalBurst=0;
	for(int i=0;i<4;i++)
	{
		cout<<"Enter burst time of process P"<<i<<" : ";
		cin>>burstTime[i];
		totalBurst += burstTime[i];
		cout<<"Enter arrival time of process P"<<i<<" : ";
		cin>>arrivalTime[i];
		cout<<"Enter priority of process P"<<i<<" : ";
		cin>>priority[i];
		waitTime[i]=0;
	}
	prioritySched(burstTime, waitTime, arrivalTime, turnaroundTime, priority, totalBurst);
	return 0;
}
