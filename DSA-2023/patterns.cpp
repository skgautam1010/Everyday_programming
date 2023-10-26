#include<bits/stdc++.h>

using namespace std;

void alphafunc(int n)
{
    for(int i=0;i<n;i++)
    {
        char ch='A'+(n-i-1);
        for(int j=0;j<=i;j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    alphafunc(n);
    return 0;
}