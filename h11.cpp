#include <iostream>
using namespace std;
int main() 
{
   int i,j,n,temp=0,arr[20];
   cout<<"Give an array number : \n";
   cin>>n;

   cout<<"enter the array elements:\n ";

   for(i=0;i<n;i++)
   {
       cin>>arr[i];
   }

   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(arr[i]<arr[j])
           {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
       }
   }
        cout<<"Descending order elements:\n";
        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }   
   return 0;
}