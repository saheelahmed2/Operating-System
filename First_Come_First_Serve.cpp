#include<iostream>
using namespace std;

int main(){
    int burst_time[10],wait_time[10],turn_around_time[10],i,n;
    float avg_wait_time,avg_tat_time;
    cout<<"\nEnter the no. of processes--";                             //Reading the no.of process
    cin>>n;
    for(int i =0;i<n;i++){
        cout<<"\nEnter the burst time for the process"<<i<<"--";        //Reading the burst time of the processes    
        cin>>burst_time[i];
    }
    wait_time[0] = avg_wait_time = 0;                                   //Wait time of first process is zero
    turn_around_time[0] = avg_tat_time = burst_time[0];     
    for(i=1;i<n;i++){
        wait_time[i] = wait_time[i-1]+burst_time[i-1];                  //calculating the wait time
        turn_around_time[i] = turn_around_time[i-1]+burst_time[i];      //calculating the turn around time
        avg_wait_time += wait_time[i];                                  //calculating the avg wait time
        avg_tat_time += turn_around_time[i];                            //calculating the avg turn around time
    }
    cout<<"\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for(i=0;i<n;i++){                                                   //displaying the burst,wait & turn around time
        cout<<"\n\tP"<<i<<"\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turn_around_time[i];
    }
    cout<<"\nAverage Waiting Time --"<<avg_wait_time/n;                 //displaying the Average Waiting time
    cout<<"\nAverage Turnaround Time --"<<avg_tat_time/n;               //displaying the Average TurnAround time
    return 0;
}
