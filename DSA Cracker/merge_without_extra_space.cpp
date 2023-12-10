// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
   
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i,j;
	    while(arr1[n-1]>arr2[0])
	    {
	        int temp=arr1[n-1];
	        arr1[n-1]=arr2[0];
	        arr2[0]=temp;
	        sort(arr1,arr1+n);
            sort(arr2,arr2+m);    
	    }
    }
};
//Another Approach

void merge(int arr1[], int arr2[], int n, int m) {
       int i=n-1;
       int j=0;
       
       while(i>=0 && j<m)
       {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);
            }
            i--;
            j++;
       }
       sort(arr1,arr1+n);
       sort(arr2,arr2+m);
    }

//Another Approach

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    void merge(int arr1[], int arr2[], int n, int m) {
        int arr[n+m];
        int i=0,j=0,k=0;
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                arr[k]=arr1[i];
                i++;
            }
            else
            {
                arr[k]=arr2[j];
                j++;
            }
            k++;
        }
        
        while(i<n)
        {
            arr[k]=arr1[i];
            i++;k++;
        }
        while(j<m)
        {
            arr[k]=arr2[j];
            j++;k++;
        }
        
        int x=0,y=0,z=0;
        while(x<n)
        {
            arr1[x]=arr[z];
            x++;
            z++;
        }
        while(y<m)
        {
            arr2[y]=arr[z];
            y++;
            z++;
        }
        
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends