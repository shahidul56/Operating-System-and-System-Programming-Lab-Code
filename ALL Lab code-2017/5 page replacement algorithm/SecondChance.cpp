#include <iostream>
#include <stdio.h>

using namespace std;
bool find_value(int arr[], int size, int key);
int main()
{
    int page_frame;
    cout<<"Enter Page Frame"<<endl;
    cin>>page_frame;
    int arr[page_frame], r[page_frame],value;

    for(int i=0; i<page_frame; i++)
        arr[i]=-1;

    printf("Enter Value\n");

    while(scanf("%d",&value))
    {
        for (int i=0; i<page_frame; i++)
            if (arr[i]==-1)
            {
                arr[i]=value;
                for (int j=0; j<page_frame; j++)
                {
                    printf("----\n");
                    (arr[j] == -1)? printf("|  |\n"):printf("|%d |\n",arr[j]);
                    printf("----\n");
                }
                if (i==page_frame-1)
                {
                    printf("\nEnter Reference Bit For these Numbers\n");
                    for (int i=0; i<page_frame; i++)
                        scanf("%d",&r[i]);
                }
                goto finish;
            }

        if (find_value(arr,page_frame,value) == false)
        {
            for (int i=0; i<page_frame; i++)
            {
                if (r[i] == 0)
                {
                    arr[i]=value;
                    break;
                }
            }
            for (int i=0; i<page_frame; i++)
            {
                printf("----\n");
                printf("|%d |\n",arr[i]);
                printf("----\n");
            }
            printf("\nEnter Reference Bit For these Numbers\n");
            for (int i=0; i<page_frame; i++)
                scanf("%d",&r[i]);
        }
        else if (find_value(arr,page_frame,value) == true )
        {
            for (int i=0; i<page_frame; i++)
            {
                printf("----\n");
                printf("|%d |\n",arr[i]);
                printf("----\n");
            }
            printf("\nEnter Reference Bit For these Numbers\n");
            for (int i=0; i<page_frame; i++)
                scanf("%d",&r[i]);
        }
finish:
        ;

    }

    return 0;
}

bool find_value(int arr[], int size, int key)
{
    for (int i=0; i<size; i++)
        if (arr[i] == key)
            return true;

    return false;
}

