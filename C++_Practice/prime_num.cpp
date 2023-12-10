#include<bits/stdc++.h>

using namespace std;


int main()
{
    int num;
    cin>>num;
    //cout<<sqrt(num)<<endl;
    int i,flag=0;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            cout<<"NoT a prime"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"prime number"<<endl;
    }
    return 0;
}