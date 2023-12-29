bool palindrome(int n)
{
    // Write your code here
    int m=n;
    int rev=0;
    while(m>0)
    {
        rev=m%10+rev*10;
        m=m/10;
    }
    if(n==rev)
    {
        return true;
    }
    else{
        return false;
    }
}