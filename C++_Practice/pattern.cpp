#include<bits/stdc++.h>

using namespace std;

int main()
{
    int row,col;
    cin>>row;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        int count=2*(row)-2*i;
        for(int j=1;j<=count;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;

    }
    for(int i=row;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        int count=2*(row)-2*i;
        for(int j=1;j<=count;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;

    }

}