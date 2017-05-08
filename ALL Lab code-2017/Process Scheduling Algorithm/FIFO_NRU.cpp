#include<iostream>
using namespace std;
int pNo,page[30],fr[10];
void fifo();
void nru();
void second_chance();
int main()
{
    int i,ch;
    cout<<"Enter the number of page:";
    cin>>pNo;
    cout<<"Enter the page sequence:\n";
    for(i=0; i<pNo; i++)
    {
        cin>>page[i];
    }
    do
    {
        cout<<"---------------------\n";
        cout<<"\tMENU\n";
        cout<<"---------------------\n";
        cout<<"\n1)FIFO";
        cout<<"\n2)NRU";
        cout<<"\n3)SECOND CHANCE";
        cout<<"\n4)Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            fifo();
            break;

        case 2:
            nru();
            break;

        case 3:
            second_chance();
            break;

        }
    }
    while(ch!=4);
}

void fifo()
{
    int pframe,j,k;
    int i,f,r,s,count,flag,num,psize;
    f=0;
    r=0;
    s=0;
    flag=0;
    count=0;

    cout<<"\nEnter the number of page frame:";
    cin>>pframe;
    for(i=0; i<pframe; i++)
    {
        fr[i]=-1;

    }
    cout<<"-------------------\n";
    cout<<"Output of all pages:\n";
    cout<<"-------------------\n";
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
            cout<<"   ----\n";
            cout<<"   |"<<fr[i]<<"|"<<"\n";

        }
        cout<<"   ----\n";

    }
    cout<<"\n";
    cout<<"Page Fault:"<<count<<"\n";

}
void nru()
{
    int array[100],dec[10];
    int pframe,j,k,decimal=0,min=99;
    int i,f,r,s,count,flag,num,psize,temp;
    f=0;
    r=0;
    s=0;
    flag=0;
    count=0;

    cout<<"\nEnter the number of page frame:";
    cin>>pframe;
    for(i=0; i<pframe; i++)
    {
        fr[i]=-1;
    }
    cout<<"-------------------\n";
    cout<<"Output of all pages:\n";
    cout<<"-------------------\n";
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
        if(flag==1)
        {
            for(i=0; i<pframe; i++)
            {
                cout<<"   ----\n";
                cout<<"   |"<<fr[i]<<"|"<<"\n";
            }
        }
        //cout<<flag;
        if(flag==0)
        {
            if(r<pframe)
            {
                fr[r]=page[s];
                for(i=0; i<pframe; i++)
                {
                    cout<<"   ----\n";
                    cout<<"   |"<<fr[i]<<"|"<<"\n";
                }
                cout<<"   ----\n";
                r++;
                s++;
                count++;
            }
            else
            {
                cout<<"Enter M & R in binary value:\n";
                for(int j=0; j<pframe; j++)
                {
                    decimal=0;
                    for(int i=0; i<2; i++)
                    {
                        cin>>array[i];
                    }

                    for(int i=0; i<2; i++)
                    {
                        decimal=decimal*2+array[i] ;

                    }
                    dec[j]=decimal;//assign the decimal value into dec;
                }
                for(int i=0; i<pframe; i++)
                {
                    if(min>dec[i])
                    {
                        min=dec[i];
                        k=i;
                    }
                }
                count++;
                fr[k]=page[s];
                s++;

                for(i=0; i<pframe; i++)
                {
                    cout<<"   ----\n";
                    cout<<"   |"<<fr[i]<<"|"<<"\n";

                }
                cout<<"   ----\n";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Page Fault:"<<count<<"\n";
}
void second_chance()
{
    int array[100],dec[10];
    int pframe,j,k,decimal=0,min=99;
    int i,f,r,s,count,flag,num,psize,temp;
    int fr[30];
    f=0;
    r=0;
    s=0;
    flag=0;
    count=0;

    cout<<"\nEnter the number of page frame:";
    cin>>pframe;
    for(i=0; i<pframe; i++)
    {
        fr[i]=-1;
    }
    cout<<"\n-------------------\n";
    cout<<"Output of all pages:\n";
    cout<<"-------------------\n";
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
        if(flag==1)
        {
            for(i=0; i<pframe; i++)
            {
                cout<<"   ----\n";
                cout<<"   |"<<fr[i]<<"|"<<"\n";
            }
        }
        //cout<<flag;
        if(flag==0)
        {
            if(r<pframe)
            {
                fr[r]=page[s];
                for(i=0; i<pframe; i++)
                {
                    cout<<"   ----\n";
                    cout<<"   |"<<fr[i]<<"|"<<"\n";
                }
                cout<<"   ----\n";
                r++;
                s++;
                count++;
            }
            else
            {
                cout<<"Enter R in binary value:\n";
                for(int j=0; j<pframe; j++)
                {
                    for(int x=0;x<1;x++)
                    {
                     cin>>array[j];
                     if(array[j]==0 || array[j]==1)
                            continue;
                        else
                        {
                            cout<<"Please input only 0 or 1\n";
                            j--;
                            break;
                        }
                        x--;
                    }
                }
                for(int j=0; j<pframe; j++)
                {
                    if(array[j]==0)
                    {
                        k=j;
                        break;
                    }
                    else
                        k=0;
                }
                count++;
                fr[k]=page[s];
                s++;

                for(i=0; i<pframe; i++)
                {
                    cout<<"   ----\n";
                    cout<<"   |"<<fr[i]<<"|"<<"\n";

                }
                cout<<"   ----\n";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Page Fault:"<<count<<"\n";
}

