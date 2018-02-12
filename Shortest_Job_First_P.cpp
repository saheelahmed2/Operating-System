#include<iostream>
#include<conio.h>
using namespace std;

int main(){
int burst_time[10],arrival_time[10],temp_burst_time[10],i,n,smallest,count=0,time;
double avg_wait_time=0,avg_turn_around_time=0,end;
cout<<"\nEnter the no. of processes--";						//reading the no. of processes
cin>>n;
for(i=0;i<n;i++){
    cout<<"\nEnter the arrival and burst time of the processes"<<i<<"--";	//reading the arrival and burst time
    cin>>arrival_time[i]>>burst_time[i];
    temp_burst_time[i]=burst_time[i];						//making a temp array for burst time
}
burst_time[9]=9999;
for(time=0;count!=n;time++){
    smallest=9;
    for(i=0;i<n;i++){								//checking if the burst time of new arrival is less
        if(arrival_time[i]<=time && burst_time[i]< burst_time[smallest] && burst_time[i]>0){
            smallest = i;							//if it is update minimum
        }
    }
    burst_time[smallest]--;							//reduce remaining burst time by 1
    if(burst_time[smallest]==0){						//if the process is completed
        count++;
        end = time +1;
       avg_wait_time += end-arrival_time[smallest]-temp_burst_time[smallest];	//calculate wait time
        avg_turn_around_time += end - arrival_time[smallest];		//calculate turn_around time

    }
}
							
cout<<"\n\nAverage Waiting Time:\t\n"<<avg_wait_time/n;					//displaying average wait time 
cout<<"\n\nAverage turnaround Time:\t\n"<<avg_tat_time/n;					//displaying average turn around time

return 0;

}
