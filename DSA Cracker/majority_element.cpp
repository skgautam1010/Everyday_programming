
/*Majority Element
Easy Accuracy: 48.6% Submissions: 57207 Points: 2

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.

Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 <= N <= 107
0 <= Ai <= 106
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // O(NLOGN)
        if(size==1)
        {
            return a[0];
        }
        sort(a,a+size);
    // your code here
    int majority=size/2;
    int count=1,temp=-1;
    for(int i=0;i<size-1;i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
            if(count>majority)
            {
                temp=a[i];
            }
            
        }
        else
        {
            count=1;
        }
    }
    
    return temp;


    //ANOTHER APPROACH O(N)

      map<int,int>mp;
        int temp=-1;
        for(int i=0;i<size;i++)
        {
            mp[a[i]]++;
        }
        int m=size/2;
        for(auto x:mp)
        {
            if(x.second>m)
            {
                temp=x.first;
            }
        }
        
        return temp;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
