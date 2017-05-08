#include <iostream>
#include <stdio.h>
using namespace std;
bool value_search(int arr[],int size, int key);
//int temp;
int main()
{
    int page_frame=0, index=0,value[100],n,temp=0;
    cout << "Enter Page Frame: " << endl;
    cin>>page_frame;
    int arr[page_frame];

    for (int i=0; i<page_frame; i++)
    {
        arr[i]=-1;
    }
    cout<<"Enter Number of Page: \n";
    cin>>n;
    cout<<"Enter Page Sequence: \n";
    for(int i=0; i<n; i++)
    {
        scanf("%d",&value[i]);
    }
    for(int i=0; i<n; i++)
    {
        // scanf("%d",&value);
        if (value_search(arr,page_frame,value[i]) == false)
        {
            temp++;
            arr[index] = value[i];
            index++;
        }

        if (index == page_frame)
            index=0;
        printf("\n\n");

        cout<<"For Entering : "<<value[i]<<endl;
        for (int i=0; i<page_frame; i++)
        {
            printf("----\n");
            if(arr[i]==-1)
            {
                printf("|  |\n");
            }
            else
            printf("| %d|\n",arr[i]);
            printf("----\n");
        }
    }
    cout<<"\nNumber of Page Fault : "<<temp<<endl;


    return 0;
}
bool value_search(int arr[],int size, int key)
{
    for (int i=0; i<size; i++)
        if (arr[i] == key)
        {
            return true;
        }

    return false;
}

