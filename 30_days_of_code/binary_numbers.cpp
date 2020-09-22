#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int rem=0,count=0,max_value=0;
    while (n>0) {
    rem=n%2;
    n=n/2;
    if (rem==1)
    {
        count++;
        if(count>max_value)
        {
            max_value=count;
        }
    }
    else {
    count=0;
    }
    }
    cout<<max_value<<endl;
    

    return 0;
}
