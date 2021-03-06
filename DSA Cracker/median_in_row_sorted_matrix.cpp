

/*

can also be solved using binary search technique

Median in a row-wise sorted Matrix
Medium Accuracy: 55.5% Submissions: 5665 Points: 4

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
*/



// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int>arr;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int temp=(n+1)/2;
        return arr[temp-1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends