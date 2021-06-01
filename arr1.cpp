#include<iostream>
using namespace std;
int main()
{
    int arr[20];
    int n,i,temp=0;
    
    cout<<"Enter the number:"<<endl;
    cin>>n;
    cout<<"Array elemnts are:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array elements ara :"<<endl;
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {

           cout<<"Even number:"<<arr[i]<<"\n";
        }
        else
        {
            cout<<" Odd number:"<<arr[i]<<"\n";
        }
        

    }
    return 0; 
}