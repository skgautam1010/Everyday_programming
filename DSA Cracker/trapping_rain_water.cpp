/*
Trapping Rain Water
Medium Accuracy: 49.62% Submissions: 35296 Points: 4

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.
*/



// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    //Naive Approach O(n^2)
    int trappingWater(int arr[], int n){
        int res=0;
        for(int i=1;i<n-1;i++)
        {
            int left=arr[i];
            for(int j=0;j<i;j++)
            {
                left=max(arr[j],left);
            }
            int right=arr[i];
            for(int j=i+1;j<n;j++)
            {
                right=max(right,arr[j]);
            }
            res=res+min(left,right)-arr[i];
        }
        return res;
    }
    //Optimized approach O(n)
    int trappingWater(int arr[], int n){
        int left[n];
        int right[n];
        
        left[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],arr[i]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],arr[i]);
        }
        int water=0;
        for(int i=0;i<n;i++)
        {
            water=water+min(left[i],right[i])-arr[i];
        }
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends