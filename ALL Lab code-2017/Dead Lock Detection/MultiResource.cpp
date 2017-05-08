#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
    int exist[20],avlable[20],curr[20][20],resource[30][30]; //defining the 2d array for the program
    int ex,pro,res;

    cout<<"Enter Number of Process : ";   //taking process number
    cin>>pro;

    cout<<"\nEnter Number of Resource : "; // taking resource number
    cin>>res;

    cout<<"\nEnter Existences values : "; //taking existence value

    for(int i=0; i<res; i++)
    {
        cin>>exist[i];
    }


    cout<<"\nEnter  Current Processes matrix : \n";      //taking value of current process matrix value

    for(int i=0; i<pro; i++)
    {
        for(int j=0; j<res; j++)
        {
            cin>>curr[i][j];
        }
    }


    cout<<"Enter Available resource values: ";         //taking first  available value

       for(int i=0;i<res;i++)
       {
           cin>>avlable[i];
       }

    cout<<"\nEnter  Resources  matrix:\n";      //taking resource matrix value

    for(int i=0; i<pro; i++)
    {
        for(int j=0; j<res; j++)
        {
            cin>>resource[i][j];
        }
    }


    bool process[50]= {false}; // make an array of all false

    int check2=0,check,temparr[50],temp,checkres;
    temp=0;

    //===========================================  WHILE STATEMNT START HERE ========================
    while(true)
    {

        check=0;
        for(int t=0; t<pro; t++)
        {
            if(process[t] == true)
            {
                check++;
            }
        }
        if(check==pro)  // all row check is complete
            break;


        for(int i=0; i<pro; i++)
        {
            checkres = 0;
            if(process[i] == false)
            {
                for(int j=0; j<res; j++)
                {
                    if(resource[i][j] <= avlable[j])  //comparing
                    {
                        checkres++;
                    }
                }
                if(checkres == res)
                {
                    process[i] = true;
                    for(int p=0; p<res; p++)
                    {
                        temparr[p] = avlable[p] - resource[i][p];
                        curr[i][p] = curr[i][p] + resource[i][p];
                        avlable[p] = temparr[p] + curr[i][p];
                    }
                    cout<<"\nAfter Finishing Process "<<"P"<<i<<"  The Available Vector is : ";
                    for(int k=0; k<res; k++)
                    {
                        cout<<" "<<avlable[k];   //printing the spate wise temp available values
                    }
                    cout<<"\n";
                    break;
                }
            }
        }




        check2++;  // means dead lock occur for the input

        if(check2 > pro)
        {
            temp=1;  //assign value to the temp
            cout<<"\nDeadlock Occurs For The Process:  ";
            for(int l=0; l<pro; l++)
            {
                if(process[l] == false)
                {
                    cout<<"P"<<l<<" ";
                }
            }
            cout<<"\n";
            break;
        }

    }


    if(temp==0) // temp == 0 means there has no deadlock happen
    {
        cout<<"\nDeadlock Does not Occur For Any Process\n";
    }
}
