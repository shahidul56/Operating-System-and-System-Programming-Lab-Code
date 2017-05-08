#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
    int segNo,memSize;
    long long int segSize[50],pos[20];
    string type;

    cout<<"Enter Number of Segment\n";
    cin>>segNo;

    for(int i=0; i<segNo; i++)
    {
        cout<<"Enter Segment Size of "<<i<<endl;
        cin>>segSize[i];

        pos[i]=i;

        cout<<"Enter Segment Type\n";
        cin>>type;

        if(type=="b"||type=="B")
            segSize[i]=segSize[i]*1;
        else if(type=="kb"||type=="KB")
            segSize[i]=segSize[i]*1024;
        else if(type=="mb"||type=="MB")
            segSize[i]=segSize[i]*1024*1024;
        else if(type=="gb"||type=="GB")
            segSize[i]=segSize[i]*1024*1024*1024;
        else if(type=="tb"||type=="TB")
            segSize[i]=segSize[i]*1024*1024*1024*1024;
    }
    string type1;

    cout<<"Enter Main Memory Size\n";
    cin>>memSize;

    cout<<"Enter Main Memory type\n";
    cin>>type1;

    if(type1=="b"||type1=="B")
        memSize=memSize*1;
    else if(type1=="kb"||type1=="KB")
        memSize=memSize*1024;
    else if(type1=="mb"||type1=="MB")
        memSize=memSize*1024*1024;
    else if(type1=="gb"||type1=="GB")
        memSize=memSize*1024*1024*1024;
    else if(type1=="tb"||type1=="TB")
        memSize=memSize*1024*1024*1024*1024;

    /*for(int i=0; i<segNo; i++)
    {
        //cout<<segSize[i]<<endl;
        cout<<"   -------\n";
        cout<<pos[i]<<" "<<"| "<<segSize[i]<<" |";
        cout<<"\n   -------\n";
    }*/


    //SegmentTable
    int segTabno,seg[50],base[50],limit[50],newseg,temp=0,totalsize,k=0,NewSegNo,offset,segmentation,flag,temp1;

    cout<<"Enter No of Segment Table\n";
    cin>>segTabno;

    while(segTabno>segNo)
    {
        cout<<"Invalid Segment Table NO,Enter Again\n";
        cin>>segTabno;
    }

    if(segTabno<=segNo)
    {
        for(int i=0; i<segTabno; i++)
        {
            if(i>0)
            {
                cout<<"Enter New Segment No..\n";
                cin>>seg[i];
                int m=0;
                while(m<i)
                {
                    if(seg[m]==seg[i])
                    {
                        cout<<"Matched With Previous Segment,Enter New Segment No\n";
                        cin>>seg[i];
                        m=-1;
                    }
                    m++;

                }
            }
            else
            {
                cout<<"Enter New Segment No.\n";
                cin>>seg[i];
            }

            while(seg[i]>=segNo)
            {
                cout<<"Invalid Segment,Please Enter Again\n";
                cin>>seg[i];
            }
            for(int j=0; j<segNo; j++)
            {
                if(seg[i]==pos[j])
                    temp=j;
            }

            cout<<"Enter Limit of segment Table Next step type\n";
            cin>>limit[i];

            string type2;

            cout<<"Enter Page Table Limit type\n";
            cin>>type2;

            if(type2=="b"||type2=="B")
                limit[i]=limit[i]*1;
            else if(type2=="kb"||type2=="KB")
                limit[i]=limit[i]*1024;
            else if(type2=="mb"||type2=="MB")
                limit[i]=limit[i]*1024*1024;
            else if(type2=="gb"||type2=="GB")
                limit[i]=limit[i]*1024*1024*1024;
            else if(type2=="tb"||type2=="TB")
                limit[i]=limit[i]*1024*1024*1024*1024;
            string type3;

            while(segSize[temp]>limit[i])
            {
                cout<<"Invalid Limit is Small than segment size,Please Enter Again\n";
                cout<<"Enter Limit of segment Table Again Next Step type\n";
                cin>>limit[i];
                cout<<"Enter Page Table Limit type New\n";
                cin>>type3;
                if(type3=="b"||type3=="B")
                    limit[i]=limit[i]*1;
                else if(type3=="kb"||type3=="KB")
                    limit[i]=limit[i]*1024;
                else if(type3=="mb"||type3=="MB")
                    limit[i]=limit[i]*1024*1024;
                else if(type3=="gb"||type3=="GB")
                    limit[i]=limit[i]*1024*1024*1024;
                else if(type3=="tb"||type3=="TB")
                    limit[i]=limit[i]*1024*1024*1024*1024;
            }

            if(i>0)
            {
                cout<<"Enter Base of segment Table\n";
                cin>>base[i];
                while(base[i]<(limit[i-1]+base[i-1]) && base[i-1]<=base[i])
                {
                    cout<<"Invalid Base,please Enter Again\n";
                    cin>>base[i];
                }
            }
            else
            {
                cout<<"Enter Base of segment Table\n";
                cin>>base[i];
            }
            totalsize=base[i]+limit[i];
            k++;
            if(totalsize>memSize)
            {
                cout<<"\n\nMemory is Full\n";
                k=i;
                break;
            }
        }
    }
    cout<<"\n\n";
    cout<<"Main Memory\n";
    for(int i=k-1; i>=0; i--)
    {
        cout<<"    "<<"      -------\n";
        cout<<seg[i]<<" "<<base[i]<<"    "<<" "<<"| "<<" |"<<"\n";
        cout<<"    "<<"      -------\n";
    }

    //Physical Address
    while(true)
    {
    cout<<"Enter Segment no\n";
    cin>>NewSegNo;
    flag=0;
    for(int i=0; i<segTabno; i++)
    {
        if(seg[i]==NewSegNo)
        {
            temp1=i;
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        cout<<"Enter Offset\n";
        cin>>offset;

        while(segSize[NewSegNo]<offset)
        {
            cout<<"Offset must be less than Segment Size,Please Enter offset Again\n";
            cin>>offset;
        }

        segmentation=base[NewSegNo]+offset;

        cout<<"The Physical Address of Segment : "<<NewSegNo<<" is : "<<segmentation<<"\n";
    }
    else
        cout<<"Segment is not Found\n";
    }
}
