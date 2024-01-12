int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    gcd(b,a%b);
}


int calcGCD(int n, int m){
    // Write your code here.
    int res=gcd(n,m);
    return res;
}