#include<iostream>
using namespace std;
int main()
{
    int array[2];
    long long int logical_size,physical_size,block_size,logical_address,offset,physical_address,k,l,m,p;
    long long int max_page_no,max_frame_number,flag=0;
    long long int page_no[100],frame_number[100],n,i,j,Npage,Nframe;
    char ch;


    //Input of Program size or logical memory
    cout<<"Logical Size & unit: ";
    cin>>logical_size>>ch;
    if(ch=='G' || ch=='g')
    {
        logical_size=logical_size*1024*1024*1024;
    }
    else if(ch=='M' || ch=='m')
    {
        logical_size=logical_size*1024*1024;
    }
    else if(ch=='K' || ch=='k')
    {
        logical_size=logical_size*1024;
    }

    else if(ch=='B' || ch=='b')
    {
        logical_size=logical_size;
    }
    else
        cout<<"Please input any unit\n";





     //input of the physical memory size
    cout<<"\nPhysical Size & unit: ";
    cin>>physical_size>>ch;
    if(ch=='G' || ch=='g')
    {
        physical_size=physical_size*1024*1024*1024;
    }
    else if(ch=='M' || ch=='m')
    {
        physical_size=physical_size*1024*1024;
    }
    else if(ch=='K' || ch=='k')
    {
        physical_size=physical_size*1024;
    }

    else if(ch=='B' || ch=='b')
    {
        physical_size=physical_size;
    }
    else
        cout<<"Please input any unit\n";



    //input of the block size
    cout<<"\nBlock Size & unit: ";
    cin>>block_size>>ch;
    if(ch=='G' || ch=='g')
    {
        block_size=block_size*1024*1024*1024;
    }
    else if(ch=='M' || ch=='m')
    {
        block_size=block_size*1024*1024;
    }
    else if(ch=='K' || ch=='k')
    {
        block_size=block_size*1024;
    }

    else if(ch=='B' || ch=='b')
    {
        block_size=block_size;
    }
    else
        cout<<"Please input any unit\n";


   //calculation of page amount, frame amount
    max_page_no = logical_size/block_size;
    max_frame_number = physical_size/block_size;

    //viewing all pages with
    cout<<"\n";
    cout<<"Maximum Page number is: "<<max_page_no<<"\n";
    cout<<"Maximum Frame number is: "<<max_frame_number<<"\n";
    cout<<"-------------------------------\n";
    cout<<"     All the physical pages\n";
    cout<<"-------------------------------\n";

    k=logical_size;

    for(i=0; i<max_page_no; i++)
    {
        l=k;
        k=k-block_size;
        cout<<" "<<k<<"-"<<l-1<<":";
        if(ch=='m' || ch=='M')
        {
            if(i>(max_page_no-2))
            {
                cout<<"\t        -----------\n";
                cout<<"\t\t        |         |\n";
            }
            else
            {
                cout<<"\t-----------\n";
                cout<<"\t\t        |         |\n";
            }
        }
        else if(ch=='k' || ch=='K')
        {
            if(i>(max_page_no-2))
            {
                cout<<"\t\t-----------\n";
                cout<<"\t\t        |         |\n";
            }
            else
            {
                cout<<"\t        -----------\n";
                cout<<"\t\t        |         |\n";
            }
        }
        else if(ch=='g' || ch=='G')
        {
            if(i>(max_page_no-2))
            {
                cout<<"\t\t-----------\n";
                cout<<"\t\t        |         |\n";
            }
            else
            {
                cout<<"-----------\n";
                cout<<"\t\t         |         |\n";
            }
        }
        else if(ch=='b' || ch=='B')
        {
            if(i>(max_page_no-2))
            {
                cout<<"\t -----------\n";
                cout<<"         |         |\n";
            }
            else
            {
                cout<<"\t -----------\n";
                cout<<"         |         |\n";
            }
        }
    }


    //printing all the Frames
    cout<<"\t\t        -----------\n";
    cout<<"\t\t---------------------------------------\n";
    cout<<"\t\t\t     All the Frames\n";
    cout<<"\t\t---------------------------------------\n";


    m=physical_size;
    for(i=0; i<max_frame_number; i++)
    {
        p=m;
        m=m-block_size;
        cout<<"\t\t "<<m<<"-"<<p-1<<":";
        if(ch=='m' ||ch=='M')
        {
            if(i>(max_frame_number-2))
            {
                cout<<"\t\t     -----------\n";
                cout<<"\t\t\t\t\t     |         |\n";
            }
            else
            {
                cout<<"\t     -----------\n";
                cout<<"\t\t\t\t\t     |         |\n";
            }
        }
        else if(ch=='k' || ch=='K')
        {
            if(i>(max_frame_number-2))
            {
                cout<<"\t\t     -----------\n";
                cout<<"\t\t\t\t\t     |         |\n";
            }
            else
            {
                cout<<"\t\t     -----------\n";
                cout<<"\t\t\t\t\t     |         |\n";
            }
        }
        else if(ch=='g' || ch=='G')
        {
            if(i>(max_frame_number-2))
            {
                cout<<"\t\t     -----------\n";
                cout<<"\t\t\t\t\t     |         |\n";
            }
            else
            {
                cout<<"    -----------\n";
                cout<<"\t\t\t\t\t     |         |\n";
            }
        }
        else if(ch=='b' || ch=='B')
        {
            if(i>(max_frame_number-2))
            {
                cout<<"\t   -----------\n";
                cout<<"\t\t\t   |         |\n";
            }
            else
            {
                cout<<"    -----------\n";
                cout<<"\t\t\t   |         |\n";
            }
        }
    }
    cout<<"\t\t\t\t\t     -----------";



    for(int j=0; j<1; j++)
    {
        cout<<"\nNumber of page & page frame with in "<<max_frame_number<<":\n";
        cin>>n;
        if(n<=max_frame_number)
        {
            cout<<"Page_no Frame_no\n";
            for(i=0; i<n; i++)
            {
                cin>>page_no[i]>>frame_number[i];
                if((page_no[i]> max_page_no) || (frame_number[i] > max_frame_number))
                {
                    cout<<"The input is out of range";
                    i--;
                    continue;
                }
            }
        }
        else
        {
            cout<<"The page number & page frame is out of range\n";
            j--;
            continue;
        }
    }



  //Calculation of logical address
    cout<<"Enter Logical Address: ";
    cin>>logical_address;
    Npage = logical_address / block_size;
    // cout<<Npage;                         //Page size = block size
    offset = logical_address % block_size;
    for(i=0; i<n; i++)
    {
        flag=0;
        if(Npage == page_no[i])      //linking and find frame value
        {
            Nframe = frame_number[i];
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        physical_address = (Nframe * block_size) + offset;
        cout<<"Physical Address: "<<physical_address;
        cout<<"\nOffset: "<<offset;
    }
    else
    {
        cout<<"Page number "<<Npage<<" is not found in the page table!!!";
    }
}

