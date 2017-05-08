#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int E[10],A[10],C[100][100],R[100][100],n,p,r,K[10],m=1,count=0;
    int flag=0,flag1[10];
    cout<<"Number of value of vectors:";
    cin>>n;
    cout<<"Enter Existing vector:";
    for(int i=0; i<n; i++)
    {
        cin>>E[i];
    }
    cout<<"Enter the number of process:";
    cin>>p;
    cout<<"Enter the number of resource:";
    cin>>r;
    cout<<"Input Current Allocation matrix C:\n";
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cin>>C[i][j];
        }
    }
    cout<<"Input Request matrix R:\n";
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cin>>R[i][j];
        }
    }
    cout<<"\nAvailable vector: ";
    for(int j=0; j<r; j++)
    {
        int temp=0;
        for(int i=0; i<p; i++)
        {
            temp=temp+C[i][j];

        }
        A[j]=E[j]-temp;
        cout<<A[j]<<" ";
    }
    for(int i=0; i<p; i++)
    {
        flag1[i]=0;
    }
    cout<<"\nOutput of Available Vector After Processing: ";
    for(int k=0; k<p; k++)
    {
        for(int i=0; i<p; i++)
        {
            if(flag1[i]==0)
            {
                flag=0;
                for(int j=0; j<r; j++)
                {
                    if(R[i][j]>A[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    for(int j=0; j<r; j++)
                    {
                        A[j]=C[i][j]+A[j];
                    }
                    flag1[i]=1;
                }
            }
        }
    }
    for(int i=0; i<r; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    for(int i=0; i<p; i++)
    {
        if(flag1[i]==1)
        {
            count++;
            if(count==p)
                cout<<"Any process is not in dead lock";
        }
        else if(flag1[i]==0)
        {
            cout<<"Process "<<i+1<<" is in dead lock\n";
        }
    }
    return 0;
}
