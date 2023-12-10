#include<bits/stdc++.h>

using namespace std;
void foo(int *p)
{
    int j=2;
    p=&j;
    cout<<*p<<endl;
}

int main()
{
    int i=97,*p=&i;
    foo(&i);
    cout<<(*p)<<endl;

}

