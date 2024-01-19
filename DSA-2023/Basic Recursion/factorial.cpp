#include<bits/stdc++.h>

using namespace std;


void fact(long long i, long long x,long long n, vector<long long> &result)
{
    if(i>n)
    {
        return;
    }
    result.push_back(i);
    i=i*x;
    fact(i,x+1,n,result);

}
vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here
    vector<long long> result;
    fact(1,2,n,result);
    return result;
   
}

//OR Solution 2

long factor(long long n)
{
    if(n==1)
    {
        return 1;
    }
    return n*factor(n-1);
}
void fact(long long i, long long n, vector<long long> &result)
{
    
    long factorial=factor(i);
    if(factorial<=n)
    {
         result.push_back(factorial);
    
        fact(i+1,n,result);
    }
    return;
   

}
vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here
    vector<long long> result;
    fact(1,n,result);
    return result;
   
}