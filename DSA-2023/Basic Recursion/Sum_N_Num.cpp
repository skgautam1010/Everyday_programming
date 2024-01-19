long long sum=0;

long long sumFirstN(long long n) {
    // Write your code here.

    
    if(n==0)
    {
        return sum;
    }
    sum=sum+n;
    sumFirstN(n-1);
}