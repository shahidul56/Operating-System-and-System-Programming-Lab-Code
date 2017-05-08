#include<iostream>
using namespace std;
int main()
{
    int n,i,AT[100],BT[100],CT=0,TAT=0,WT=0,TWT=0,k=0;
    float Avg_wt=0.0f;
    cout<<"Enter number of phases:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter AT and BT for process "<<i+1<<":";
        cin>>AT[i]>>BT[i];
    }
    cout<<"Process Name"<<"\t"<<"TAT"<<"\t\t"<<"WT";
    for(i=0;i<n;i++)
    {
        CT +=BT[i];
        TAT = CT-AT[i];
        WT = TAT-BT[i];
        cout<<"\nP"<<i+1<<"\t\t"<<TAT<<"\t\t"<<WT;
        TWT = TWT+WT;
    }
    Avg_wt=(TWT/(n*1.00f));
    cout<<"\n\nTotal waiting time:"<<TWT;
    cout<<"\nAverage waiting time:"<<Avg_wt;
    cout<<"\n\nGantt Chart:\n";
    cout<<" --------------------------\n";
    cout<<"| ";
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<" | ";
    }
    cout<<"\n --------------------------\n";
    for(i=0;i<n;i++)
    {
        k +=BT[i];
        if(i==0){
        cout<<AT[i]<<"    "<<BT[i];
        }
        else
            cout<<"    "<<k;
    }
}
