#include<iostream>
using namespace std;
int main()
{
    int pNo,pframe,j,k;
    int i,f,r,s,count,flag,num,psize;
    int page[30],fr[30];
    f=0;
    r=0;
    s=0;
    flag=0;
    count=0;
    cout<<"Enter the number of page:";
    cin>>pNo;


    cout<<"Enter the pages:\n";
    for(i=0; i<pNo; i++)
    {
        cin>>page[i];
    }
    cout<<"\nEnter the number of page frame:";
    cin>>pframe;
    for(i=0; i<pframe; i++)
    {
        fr[i]=-1;

    }

    cout<<"Output:\n";
    while(s<pNo)
    {
        flag=0;
        num=page[s];
        for(i=0; i<pframe; i++)
        {
            if(num==fr[i])
            {
                s++;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(r<pframe)
            {
                fr[r]=page[s];
                r++;
                s++;
                count++;
            }
            else
            {
                if(f<pframe)
                {
                    fr[f]=page[s];
                    s++;
                    f++;
                    count++;
                }
                else
                {
                    f=0;
                    continue;
                }
            }
        }
        cout<<"\n";

        for(i=0; i<pframe; i++)
        {
            cout<<"----\n";
            cout<<"|"<<fr[i]<<"|"<<"\n";

        }
        cout<<"----\n";

    }
    cout<<"\n";
    cout<<"Page Fault:"<<count;

}
