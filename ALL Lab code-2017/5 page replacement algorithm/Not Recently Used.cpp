#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int pageno,frameno,flag,temp1=0,temp2=0;
    cout<<"Enter The No Of Page : \n";
    cin>>pageno;

    int page[pageno];
    cout<<"Enter Page Sequence : \n";
    for(int i=0; i<pageno; i++)
    {
        cin>>page[i];
    }
    cout<<"Enter The No of Frame : ";
    cin>>frameno;

    int nruframe[frameno];
    //Rest of the part of the frame is set to zero
    if(pageno<frameno)
    {
        for(int i=pageno; i<frameno; i++)
            page[i]=0;
    }
    //Initially frame is Zero
    for(int i=0; i<frameno; i++)
    {
        nruframe[i]=-1;
    }


    //for(int i=0; i<frameno; i++)
    int p=0,index=0;
    while(temp1<frameno)
    {
        //int i=p;
        if(p==0)
        {
            temp1++;
            nruframe[index++]=page[p];
            for (int j=0; j<frameno; j++)
            {
                printf("----\n");
                if(nruframe[j]==-1)
                {
                    printf("|  |\n");
                }
                else
                    printf("| %d|\n",nruframe[j]);
                printf("----\n");
            }
        }
        else
        {
            flag=0;
            for(int k=0; k<frameno-p; k++)
            {
                if(nruframe[k]==page[p])
                {
                     flag=1;
                     temp2++;
                   //  break;
                }
            }
            if(flag==0)
            {
                temp1++;
                nruframe[index++]=page[p];
                for (int j=0; j<frameno; j++)
                {
                    printf("----\n");
                    if(nruframe[j]==-1)
                    {
                        printf("|  |\n");
                    }
                    else
                        printf("| %d|\n",nruframe[j]);
                    printf("----\n");
                }
            }
        }
        p++;
    }
    int min,min_ind,ref,mod,temp;
    for(int i = (frameno+temp2); i<pageno; i++)
    {
        min=65455;
        cout<<"Enter the reference Bit and Modification bit:\n";
        cout<<"For Entering : "<<page[i]<<endl;
        for(int j=0; j<frameno; j++)
        {
            cin>>ref>>mod;
            if(ref==0 && mod==0)
            {
                temp=0;
            }
            else if(ref==0 && mod==1)
            {
                temp=1;
            }
            else if(ref==1 && mod==0)
            {
                temp=2;
            }
            else if(ref==1 && mod==1)
            {
                temp=3;
            }
            if(temp<min)
            {
                min=temp;
                min_ind=j;
            }
        }

        printf("   ___\n");
          int  flag1=0;
            for(int k=0; k<frameno; k++)
            {
                if(nruframe[k]==page[i])
                {
                     flag1=1;
                     //temp2++;
                   //  break;
                }
            }
            if(flag1==0)
                nruframe[min_ind]=page[i];
        for(int j=0; j<frameno; j++)
        {
            printf("%d",j);
            printf(" |");
            printf(" %d |\n",nruframe[j]);
            printf("   ___\n");
        }
        printf("\n\n");
        if(i!=pageno-1)
            printf("___\n");
    }

}
