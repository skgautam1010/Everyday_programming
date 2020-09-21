#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int testcase;
    cin>>testcase;  
    for(int i=0;i<testcase;i++)
    {
        string str;
    string res1,res2;
    cin>>str;
    for(int i=0;i<str.length();i++)
    {
        if(i%2==0)
        {
        res1 +=str[i];
        }
        else {
        res2 +=str[i];
        }
    }
    cout<<res1<<" "<<res2<<endl;
    }
    return 0;
}
