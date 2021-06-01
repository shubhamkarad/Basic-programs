#include<iostream>
using namespace std;
int main()
{
    int m=0,flag=0;
    int i,n;
    cout<<"\n enter the number :";
    cin>>n;
    m=n/2;
    for(i=2;i<m;i++)
    {
        if(n%i==0)
        {
            cout<<"is not prime number"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<n<<" is prime number";
    }
    return 0;

}