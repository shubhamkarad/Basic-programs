#include<iostream>
using namespace std;
int main()
{
    int i,n=8,count=0;
    int arr[8]={0,1,1,0,1,0,0,0};
    for(i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            count++;

        }
    }
    for(i=0;i<n;i++)
    {
        if(i < count)
        {
            arr[i] == 0;
        }
        else
        {
            
            arr[i] == 1;
                    }
        
    }
        return 0;
}
