#include<iostream>
using namespace std;
int main(){
	int i,size,j,temp=0;
	float avg_wait_time=0,avg_tat_time=0;
	cout<<"\nEnter the no. of process";							 //Reading the no.of process
	cin>>size;
	int arrival_time[size],burst_time[size],priority[size],waiting_time[size],turn_around_time[size],process[size];
	cout<<"\nEnter the priority,arrival time and burst time of the process\n";		

	for(int i=0;i<size;i++){
		cin>>process[i]>>priority[i]>>arrival_time[i]>>burst_time[i];				//Reading the attributes of the processes
	}
	
	waiting_time[0]=avg_wait_time=0;												//Wait time of first process is zero
	turn_around_time[0]=avg_tat_time=burst_time[0];

																					///*Sorting According to Arrival Time*/
	for(i=1;i<size;i++){
		for(j=i+1;j<size;j++){
			if((priority[i]>priority[j]) && (arrival_time[i] < arrival_time[j])){
				temp=priority[i];
				priority[i]=priority[j];
				priority[j]=temp;

				temp=burst_time[i];
				burst_time[i]=burst_time[j];
				burst_time[j]=temp;

				temp=arrival_time[i];
				arrival_time[i]=arrival_time[j];
				arrival_time[j]=temp;

				temp=process[i];
				process[i]=process[j];
				process[j]=temp;				
			}
		}
		
	}
	

	for(i=1;i<size;i++){
		waiting_time[i] =waiting_time[i-1]+burst_time[i-1];
		
		turn_around_time[i] = turn_around_time[i-1]+burst_time[i];

		avg_wait_time+=waiting_time[i];
		avg_tat_time+=turn_around_time[i];
	}
	for(i=1;i<size;i++){
	    waiting_time[i]-=arrival_time[i];
	}

	cout<<"\tPROCESS\t\tPRIORITY\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";		//displaying the burst,wait & turn around time
	for(i=0;i<size;i++){							
		cout<<"\n\tP"<<process[i]<<"\t\t"<<priority[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i];
	}

	cout<<"\nAverage Waiting Time --"<<avg_wait_time/size;												//displaying the Average Waiting time
    cout<<"\nAverage Turnaround Time --"<<avg_tat_time/size;											//displaying the Average TurnAround time
    return 0;

}