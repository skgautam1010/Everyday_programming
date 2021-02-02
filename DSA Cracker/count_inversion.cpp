// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long int invMerge(long long arr[], long long l,long long m,long long r)
{
    long long int n1=m-l+1,n2=r-m,a1[n1],a2[n2];
    for(int i=0;i<n1;i++){a1[i]=arr[l+i];}
    for(int i=0;i<n2;i++){a2[i]=arr[m+i+1];}
    long long int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j]){arr[k]=a1[i];i++;}
        else{arr[k]=a2[j];j++;res+=(n1-i);}
        k++;
    }
    while(i<n1){arr[k]=a1[i];i++;k++;}
     while(j<n2){arr[k]=a2[j];j++;k++;}
     return res;
}
// Function to find inversion count in the array
long long int inv(long long arr[], long long l,long long r)
{
    long long int ct=0;
    if(l<r)
    {
        long long int m=(l+r)/2;
        ct+=inv(arr,l,m);
        ct+=inv(arr,m+1,r);
        ct+=invMerge(arr,l,m,r);
    }
    return ct;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long int res=inv(arr,0,N-1);
    return res;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends