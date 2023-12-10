#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m,flag;
    cin>>n;
    
    for(int j=0;j<n;j++)
    {
        int temp;
        cin>>temp;
        //m=sqrt(temp);
        if(temp==1)
        {
            cout<<"Not prime\n";
            break;
        }
        for(int i=2;i*i<=temp;i++)
        {
            flag=0;
            if(temp%i==0)
            {
                cout<<"Not prime\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Prime\n";
        }
        
    }
    
    return 0;
}
