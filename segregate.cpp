#include<iostream>
using namespace std;
int main()
{
    int n=8;
    int arr[8] = {0,1,1,0,1,0,0,0};
    int count = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            <<count(arr.begin(), arr.end(), 0);

        }
    }
    for(i=0;i<n;i++)
    {
        if(i<arr.count)
        {
            arr[i] == 0;
        }
        else
        {
            
            arr[i] == 1;
        }
    }
     for(i=0;i<n;i++)
    {
        cout<<arr[i];
    }


        return 0;
}
