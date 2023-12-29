#include<bits/stdc++.h>

using namespace std;

int reverse(int x) {
        long long rev=0;
        while(x)
        {
            long long m=x%10;
            rev=m+rev*10;
            x=x/10;
        }
       if(rev>INT_MAX || rev<INT_MIN)
       {
           return 0;
       }
        return rev;
    }