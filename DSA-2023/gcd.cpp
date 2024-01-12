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


//second approach




int calcGCD(int n, int m){
    // Write your code here.
   while(n>0 && m>0)
   {
       if(n>m)
       {
           n=n%m;
       }
       else{
           m=m%n;
       }
   }
   if(n==0)
   {
       return m;
   }
   else{
       return n;
   }
}