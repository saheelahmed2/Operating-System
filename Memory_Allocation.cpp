#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{   
    int blockSize[5],processSize[5],temp[5],i=0,j=0,k=0,n,m,count=0,choice;
    cout<<"\nEnter the count of process--";         
    cin>>n;
    cout<<"\nEnter the count of block--";
    cin>>m;                                 
    cout<<"\nEnter the no. of process--";
    for( i=0;i<n;i++)
        cin>>processSize[i];                                 //reading the process size
    cout<<"\nEnter the no. of blocks--";
    for( j=0;j<m;j++)
        cin>>blockSize[j];                                  //reading the block size
    for( k=0;k<n;k++)
        temp[k]=-1;                                         //keeping temporary for block no.
    cout<<"Enter choice:\n1.First Fit\n2.Best Fit\n3.Worst Fit\n";
    cin>>choice;
    switch(choice){
        case 1: for(i=0;i<n;i++){                    //Code for allocating memory blocks using first fit
                    for(j=0;j<m;j++){
                        if(processSize[i] <= blockSize[j] && blockSize[j]!=0){
                            temp[i]=j;
                            blockSize[j]-=processSize[i];
                            break;
                        }
                    }
                }    
                break;
        case 2: for(i=0;i<n;i++){                    //Code for allocating memory blocks using best fit
                    int diff=9999;
                    for(j=0;j<m;j++){
                        if(processSize[i] <= blockSize[j] & blockSize[j]!=0 && (blockSize[j]-processSize[i])<diff){
                            diff = blockSize[j]-processSize[i];             //selecting the block with min diff.    
                            count=j;
                        }
                    }
                    if(diff!=0){
                        blockSize[count]-=processSize[i];                   //decrementing the block size
                        temp[i]=count;                                      //assigning the block no.
                    }                                                   
                }   
                break;
        case 3: for(i=0;i<n;i++){                    //Code for allocating memory blocks using worst fit
                    int diff=0;
                    for(j=0;j<m;j++){
                        if(processSize[i] <= blockSize[j] & blockSize[j]!=0 && (blockSize[j]-processSize[i])>diff){
                            diff = blockSize[j]-processSize[i];             //selecting the block with max diff.    
                            count=j;
                        }
                    }
                    if(diff!=0){
                        blockSize[count]-=processSize[i];                   //decrementing the block size
                        temp[i]=count;
                    }                                                       //assigning the block no.
                }    
                break;
        default: cout<<"Wrong choice\n";    
    }
    cout<<"\nProcess No.\t Process Size\tBlock no.\n";
    for(i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if(temp[i]!= -1)
            cout<< temp[i]+1;
        else
            cout<< "Not Allocated";
        cout<< endl;    
    }
    
    return 0;
}
