#include<stdio.h>
#include <iostream>
using namespace std;
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;
bool value_search(int arr[],int size, int key);


//=============================================== OPTIMAL ======================================================
void optimal()
{


    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");  //taking input of Frame number
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: "); // taking input of how many pages
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");  //taking all page value

    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);         //storing page values
    }

    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;                 //putting pages value to the frame

        for(j = 0; j < no_of_frames; ++j){  //putting pages value to the frame and making flag value
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;        // for putting value flag=1
                                              //if empty flag =0
                   break;
               }
        }

        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;                    //calculating the page fault
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            flag3 =0;

            for(j = 0; j < no_of_frames; ++j){
                temp[j] = -1;

                for(k = i + 1; k < no_of_pages; ++k){
                    if(frames[j] == pages[k]){
                        temp[j] = k;        //frame[] = how many frame //pages[]=all page value
                        break;
                    }
                }
            }

            for(j = 0; j < no_of_frames; ++j){
                if(temp[j] == -1){
                    pos = j;                   // replacing -1 value of the frame with value
                    flag3 = 1;
                    break;
                }
            }

            if(flag3 ==0){
                max = temp[0];
                pos = 0;

                for(j = 1; j < no_of_frames; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];          //Also calculating page faults for the frame
            faults++;
        }

        printf("\n");

        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);     //printing all of the frame value
        }

    }

    printf("\n\nTotal Page Faults = %d", faults);

}


//========================================================= FIFO ============================================
   void  fifo()
   {
     int page_frame=0, index=0,value[100],n,temp=0;

    cout << "Enter number of Frame : " << endl;
    cin>>page_frame;                        //taking frame

    int arr[page_frame];

    for (int i=0; i<page_frame; i++)
    {
        arr[i]=-1;
    }
    cout<<"Enter Number of Pages: \n";
    cin>>n;

    cout<<"Enter Page value: \n";
    for(int i=0; i<n; i++)
    {
        scanf("%d",&value[i]);              //storing all page
    }

    for(int i=0; i<n; i++)
    {
        // scanf("%d",&value);
        if (value_search(arr,page_frame,value[i]) == false)
        {
            temp++;                      //temp mean the number of  pagefults
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



}

bool value_search(int arr[],int size, int key)
{
    for (int i=0; i<size; i++)
        if (arr[i] == key)              // is value is comming first or not //measuring the position
        {
            return true;
        }

    return false;

   }

   //=================================================================== SECOND CHANCE =================================
   void secondchance()
   {



    int i,j,k,page[1000],frame[1000],page_no,frame_no,avail,count=0,refbit[1000],check1=1,check,bitcount=0;

    printf("\n Enter the number of pages:\n");
    scanf("%d",&page_no);                        //taking page amount

    printf("\nEnter the page value:\n");        //taking page value
    for(i=0; i<page_no; i++)
    {
        scanf("%d",&page[i]);
       // page++;
    }

    printf("\nEnter the number of frames:\n");           //taking number of frame
    scanf("%d",&frame_no);
    for(i=0; i<frame_no; i++)
    {
        frame[i]=-1;
    }
    j=0;
    for(i=0; i<page_no; i++)
    {

        avail=0;
        for(k=0; k<frame_no; k++)
        {
            if(frame[k]==page[i])
            {
                avail=1;
            }
        }
        if(avail==0)
        {
            if(refbit[j]==0)
            {
                frame[j]=page[i];
                j=(j+1)%frame_no;
                check=0;
                check1=0;

            }
            else if(refbit[j]==1)
            {
                j=(j+1)%frame_no;
                check=1;
                check1=1;
                bitcount++;
                i--;
            }
            else
            {
                frame[j]=page[i];
                j=(j+1)%frame_no;
                check=0;
            }

            if(check==0)
            {
                printf("for page:%d\n",page[i]);
                count++;
                for(k=0; k<frame_no; k++)
                {
                    printf("%d\n",frame[k]);
                }
            }


            if(check==1&&bitcount==frame_no){
                for(k=0; k<frame_no; k++)
                {
                    printf("%d\n",frame[k]);
                }
                bitcount=0;
            }


            if(j==0||check1==0)
            {     j=0;
                for (int k = 0; k < frame_no; k++)
                {      if(i==page_no-1)
                      break;
                    printf("Input Reference bit 0 or 1 for %d: ",frame[k]);
                    scanf("%d",&refbit[k]);                               //taking referance bit



                }

            }
        }
        else
        {
            for(k=0; k<frame_no; k++)
            {

                printf("%d\n",frame[k]);


            }
            printf("\n");


            for (int k = 0; k < frame_no; k++)
                {      if(i==page_no-1)
                      break;
                    printf("Input Reference bit 0 or 1 for %d: ",frame[k]);
                    scanf("%d",&refbit[k]);



                }

        }


    }

    printf("\n\npage fault%d",count);
    }


//================================================= NRU ===========================================


void nru()
{

}









//================================================= CLOCK =========================================




void clock()
{


}



//============================================= MAINFUNCTION =====================================


int main()
{
    int choice;
    while(1)
    {
        printf("\nPage Replacement Algorithms\n1.\Optimal Page Replacement Algorithm\n2.FIFO\n3.Second Chance\n4.NRU\n5.Clock\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
           optimal();
            break;
          case 2:
           fifo();
            break;
        case 3:
            secondchance();
            break;
        case 4:
            nru();
            break;
        case 5:
            clock();
            break;

        default:
            return 0;
            break;
        }
    }
}
